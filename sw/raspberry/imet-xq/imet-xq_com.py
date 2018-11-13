#!/usr/bin/python3

__author__ = 'gdiaz'

# iMet-XQ ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
"""

import zmq
import sys
import time
import re
import argparse
import json
import serial

from threading import Thread
from time import sleep

# Get Nodes and Ports Parameters
with open('node_list.json', encoding='utf-8') as data_file:
    data = json.load(data_file)

NODE_IMET = data["nodes"]["imet"]
NODE_OBC = data["nodes"]["obc"]
CSP_PORT_APPS = data["ports"]["telemetry"]

#define commands
GET_DATA = "get_imetxq_data"

class iMetXQComInterface:
    def __init__(self):
        # sensor arguments
        #com args
        self.node = chr(int(NODE_IMET)).encode("ascii", "replace")
        self.node_dest = NODE_OBC
        self.port_csp = CSP_PORT_APPS
        self.prompt = "[node({}) port({})] <message>: "
        # imet-xq interface
        self.serial_port = serial.Serial("/dev/ttyUSB0", "57600", timeout=5)
        self.pressure = 0
        self.temperature = 0
        self.humidity = 0
        self.date = "0"
        self.time = "0"
        self.latitude = "0"
        self.longitude = "0"
        self.altitude = 0
        self.satellites = 0

    def update_data(self):
        while True:
            try:
                data = self.serial_port.read(81)
                self.pressure = int(data[5:12])
                self.temperature = int(data[13:18])
                self.humidity = int(data[19:24])
                self.date = data[25:35]
                self.time = data[36:44]
                self.latitude = data[45:56]
                self.longitude = data[57:68]
                self.altitude = int(data[69:78])
                self.satellites = int(data[79:81])
            except:
                self.serial_port.flush()

    def console(self, ip="localhost", in_port_tcp=8002, out_port_tcp=8001):
        """ Send messages to node """
        ctx = zmq.Context()
        pub = ctx.socket(zmq.PUB)
        sub = ctx.socket(zmq.SUB)
        sub.setsockopt(zmq.SUBSCRIBE, self.node)
        pub.connect('tcp://{}:{}'.format(ip, out_port_tcp))
        sub.connect('tcp://{}:{}'.format(ip, in_port_tcp))
        print('Start iMet-XQ Intreface as node:" {},'.format(int.from_bytes(self.node, byteorder='little')))

        while True:
            frame = sub.recv_multipart()[0]
            header_a = ["{:02x}".format(i) for i in frame[1:5]]
            header = "0x"+"".join(header_a[::-1])
            data = frame[5:]
            try:
                csp_header = parse_csp(header)
            except:
                csp_header = ""
            # data = data[:-1]
            print('\nMON:', frame)
            print('\tHeader: {},'.format(csp_header))
            print('\tData: {}\n'.format(data))
            cmd = data.decode("ascii", "replace")
            # try:
            if(cmd==GET_DATA):
                print('\nMeasurements:')
                print('\tPressure: {}'.format(self.pressure))
                print('\tTemperature: {},'.format(self.temperature))
                print('\tHumidity: {}'.format(self.humidity))
                # build msg
                #          Prio   SRC   DST    DP   SP  RES HXRC
                header_ = "{:02b}{:05b}{:05b}{:06b}{:06b}00000000"

                prompt = self.prompt.format(self.node_dest, self.port_csp)
                # Get CSP header_ and data
                hdr = header_.format(1, int.from_bytes(self.node, byteorder='little'), self.node_dest, self.port_csp, 63)

                # Build CSP message
                hdr_b = re.findall("........",hdr)[::-1]
                # print("con:", hdr_b, ["{:02x}".format(int(i, 2)) for i in hdr_b])
                hdr = bytearray([int(i,2) for i in hdr_b])
                # join data
                data_ = " ".join([str(self.pressure), str(self.temperature), str(self.humidity), str(self.date), str(self.time), str(self.latitude), str(self.longitude), str(self.altitude), str(self.satellites)])
                msg = bytearray([int(self.node_dest),]) + hdr + bytearray(data_, "ascii")
                # send data to OBC node
                try: pub.send(msg)
                except Exception as e: pass
                cmd = ""
            # except:
            #     print("iMet-XQ disconnected")


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

    imetxq = iMetXQComInterface()

    tasks = []

    # Create a update data thread
    data_th = Thread(target=imetxq.update_data)
    # data_th.daemon = True
    tasks.append(data_th)
    data_th.start()

    if args.ncon:
        # Create a console socket
        console_th = Thread(target=imetxq.console, args=(args.ip, args.out_port, args.in_port))
        # console_th.daemon = True
        tasks.append(console_th)
        console_th.start()

    for th in tasks:
        th.join()
