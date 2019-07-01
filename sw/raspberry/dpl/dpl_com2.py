#!/usr/bin/python

__author__ = 'gdiaz'

# DPL ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for dpl data exchange.
"""

"""Description
    DPL comunication: node1 & node2

    commands: read cmds(int) from node1 and execute cmd
    console:  send state(int, int) to node2

                              -> node1 -> commands[SUB]-->method
    state-->console[PUB]-> node2

"""

import zmq
import sys
import time
import re
import argparse
import json
import codecs
import struct
from smbus2 import SMBus

from threading import Thread
from gpiozero import *
from time import sleep

sys.path.append('../')

# Get Nodes and Ports Parameters
with open('node_list.json') as data_file:
    data = json.load(data_file)

NODE_DPL = data["nodes"]["dpl"]
NODE_OBC = data["nodes"]["obc"]
CSP_PORT_APPS = data["ports"]["telemetry"]

DPL_I2C_ADDR = 0x06

#define commands
OPEN1 = "open_dpl_1"
OPEN2 = "open_dpl_2"
OPEN3 = "open_dpl_3"
OPEN4 = "open_dpl_4"
OPEN5 = "open_dpl_5"
OPEN6 = "open_dpl_6"
GET_DATA = "get_dpl_data"

class DplComInterface:
    def __init__(self):
        #i2c comm
        self.bus = SMBus(1)
        #Linear Actuator Activation Pins
        self.state = 0
        #com args
        self.node = chr(int(NODE_DPL)).encode("ascii", "replace")
        self.node_dest = NODE_OBC
        self.port_csp = CSP_PORT_APPS
        self.prompt = "[node({}) port({})] <message>: "

    def start(self):
        return True

    def deploy_port(self, port):
        try:
            self.bus.write_byte_data(DPL_I2C_ADDR, ord('D'), ord('D'))
        except:
            pass
        print("deployed port %d" %(port))

    def get_port_status(self, port):
        try:
            self.state = self.bus.write_byte_data(DPL_I2C_ADDR, ord('S'), port)
        except:
            self.state = -1
        print(type(self.state))
        if type(self.state) == type(None):
            self.state = -2

    def get_status(self):
        try:
            self.state = self.bus.read_byte_data(DPL_I2C_ADDR, ord('R'))
        except:
            self.state = -1

    def console(self, ip="localhost", in_port_tcp=8002, out_port_tcp=8001):
        """ Send messages to node """
        ctx = zmq.Context()
        pub = ctx.socket(zmq.PUB)
        sub = ctx.socket(zmq.SUB)
        sub.setsockopt(zmq.SUBSCRIBE, self.node)
        pub.connect('tcp://{}:{}'.format(ip, out_port_tcp))
        sub.connect('tcp://{}:{}'.format(ip, in_port_tcp))
        print('Start Deployment Intreface as node: {}'.format(int(codecs.encode(self.node, 'hex'), 16)))

        while True:
            frame = sub.recv_multipart()[0]
            header_a = []
            for byte in frame[1:5]:
                byte_int = int(codecs.encode(byte, 'hex'), 16)
                byte_hex = hex(byte_int)
                header_a.append(byte_hex[2:])
            header = "0x"+"".join(header_a[::-1])
            data = frame[5:]
            try:
                csp_header = parse_csp(header)
            except:
                csp_header = ""
            data = data[:-1]
            print('\nMON:', frame)
            print('\tHeader: {},'.format(csp_header))
            print('\tData: {}'.format(data))
            #cmd = data.decode("ascii", "replace")
            cmd = data.decode("utf-8")

            if cmd == GET_DATA:
                #update data
                self.get_status()
                #self.get_port_status(0)
                print('\tPort States: {},'.format(self.state))
                # build msg
                #          Prio   SRC   DST    DP   SP  RES HXRC
                header_ = "{:02b}{:05b}{:05b}{:06b}{:06b}00000000"

                prompt = self.prompt.format(self.node_dest, self.port_csp)
                # Get CSP header_ and data
                hdr = header_.format(1, int(codecs.encode(self.node, 'hex'), 16), self.node_dest, self.port_csp, 63)

                # Build CSP message
                hdr_b = re.findall("........",hdr)[::-1]
                # print("con:", hdr_b, ["{:02x}".format(int(i, 2)) for i in hdr_b])
                hdr = bytearray([int(i,2) for i in hdr_b])
                # join data
                n_frame = 0
                # BMP Telemetry Type
                fr_type = 16
                n_samples = 1
                data_ = bytearray(struct.pack('hhi', n_frame, fr_type, n_samples))
                data_ = data_ + \
                        struct.pack('Ii', int(time.time()), self.state)
                msg = bytearray([int(self.node_dest),]) + hdr + data_
                # send data to OBC node
                try:
                    pub.send(msg)
                except Exception as e:
                    pass
            elif cmd == OPEN1 or cmd == OPEN2 or cmd == OPEN3 or cmd == OPEN4 or cmd == OPEN5 or cmd == OPEN6:
                # execute cmd from OBC node
                port = int(cmd[-1])-1
                self.deploy_port(port)
            else:
                print("Invalid command")
            time.sleep(0.25)


def get_parameters():
    """ Parse command line parameters """
    parser = argparse.ArgumentParser()

    parser.add_argument("-n", "--node", default=10, help="Node address")
    parser.add_argument("-d", "--ip", default="localhost", help="Hub IP address")
    parser.add_argument("-i", "--in_port", default="8001", help="Hub Input port")
    parser.add_argument("-o", "--out_port", default="8002", help="Hub Output port")
    parser.add_argument("--nmon", action="store_false", help="Disable monitor task")
    parser.add_argument("--ncon", action="store_false", help="Disable console task")

    return parser.parse_args()

if __name__ == '__main__':
    # Get arguments
    args = get_parameters()

    dpl_com = DplComInterface()

    tasks = []

    if args.ncon:
        # Create a console socket
        console_th = Thread(target=dpl_com.console, args=(args.ip, args.out_port, args.in_port))
        # console_th.daemon = True
        tasks.append(console_th)
        console_th.start()

    for th in tasks:
        th.join()
