#!/usr/bin/python3

__author__ = 'gdiaz'

# Iridium ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
    BMP comunication: node1

    console:  send data to node1

    data[ird]-->console[PUB]-> node1

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

NODE_IRD = data["nodes"]["ird"]
NODE_OBC = data["nodes"]["obc"]
CSP_PORT_APPS = data["ports"]["telemetry"]

#define commands
GET_DATA = "get_prs_data"

class IrdComInterface:
    def __init__(self):
        # sensor arguments
        #com args
        self.node = chr(int(NODE_IRD)).encode("ascii", "replace")
        self.node_dest = NODE_OBC
        self.port_csp = CSP_PORT_APPS
        self.prompt = "[node({}) port({})] <message>: "
        # iridium interface
        self.serial_port = serial.Serial("/dev/iridium", "19200", timeout=5)
        self.last_data = b"none"
        self.data_succed = False

    def get_msg(self, data):
        msg = ""
        for elem in data:
            msg = msg + " " + str(elem)
        return msg[1:]

    def console(self, ip="localhost", in_port_tcp=8002, out_port_tcp=8001):
        """ Send messages to node """
        ctx = zmq.Context()
        sub = ctx.socket(zmq.SUB)
        sub.setsockopt(zmq.SUBSCRIBE, self.node)
        sub.connect('tcp://{}:{}'.format(ip, in_port_tcp))
        print('Start Iridium Intreface as node:" {},'.format(int.from_bytes(self.node, byteorder='little')))

        while True:
            frame = sub.recv_multipart()[0]
            header_a = ["{:02x}".format(i) for i in frame[1:5]]
            header = "0x"+"".join(header_a[::-1])
            data = frame[5:]
            try:
                csp_header = parse_csp(header)
            except:
                csp_header = ""
            data = data[:-1]
            # print('\nMON:', frame)
            # print('\tHeader: {},'.format(csp_header))
            # print('\tData: {}\n'.format(data))
            cmd = data.decode("ascii", "replace")
            try:
                if(cmd=="StartingMission" or cmd=="EndMission"):
                    print("\nIridium DATA: ", cmd.encode())
                    msg_iridium = b"AT+SBDWT="+cmd.encode()+b"\r"
                else:
                    msg = cmd[4:].split(" ")
                    msg = self.get_msg(msg[:-1])
                    print("\nIridium DATA: ", msg.encode())
                    msg_iridium = b"AT+SBDWT="+msg.encode()+b"\r"
                self.last_data = msg_iridium
                self.serial_port.flush()
                self.serial_port.write(msg_iridium)
                self.serial_port.flush()
                self.serial_port.write(b"AT+SBDIX\r")
                self.serial_port.write(b"AT+SBDIX\r")
                self.serial_port.flush()
            except:
                print("iridium disconnected")
            
            #data = self.serial_port.readline()
            #if (len(data)) and (not data == '\r'):
                #print("\nIridium REPLY: ", data)
                # print(data)
            #else:#retry ones
            #    self.serial_port.flush()
            #    self.serial_port.write(self.last_data)
            #    self.serial_port.flush()
            #    self.serial_port.write(b"AT+SBDIX\r")
                #print("sending last data")

    def iridium_reply(self):
        data_end = False
        while True:
            try:
                #self.serial_port.flush()
                data = self.serial_port.read(100)
                if (len(data)):
                    print("\nIridium REPLY: ", data)
                """if (len(data)) and (not data == '\r'):
                    print("\nIridium REPLY: ", data)
                    data_end = True
                if data_end:
                    d_dec = data.decode("ascii", "replace")
                    msg_rep = d_dec[4:].split(" ")
                    rply = self.get_msg(msg_rep[:-1])
                    print("rply=", msg_rep)
                    self.serial_port.flush()
                    data_end = False
                if self.data_succed:
                    #self.serial_port.flush()
                    self.serial_port.write(self.last_data)
                    self.serial_port.flush()
                    self.serial_port.write(b"AT+SBDIX\r")
                    print("\nsending last data:", self.last_data)
                    self.data_succed = True""" 

            except UnicodeDecodeError as e:
                print(e)
                pass

            except serial.SerialException as e:
                print(e)
                pass


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

    bmp = IrdComInterface()

    # bmp.console()

    tasks = []

    if args.ncon:
        # Create a console socket
        console_th = Thread(target=bmp.console, args=(args.ip, args.out_port, args.in_port))
        # console_th.daemon = True
        tasks.append(console_th)
        console_th.start()

    # Create a console socket
    ird_th = Thread(target=bmp.iridium_reply)
    tasks.append(ird_th)
    ird_th.start()

    for th in tasks:
        th.join()
