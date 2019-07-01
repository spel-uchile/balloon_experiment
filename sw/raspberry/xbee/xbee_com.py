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
import codecs

import os.path
import glob
import datetime

from threading import Thread
from time import sleep

from xbee import xBeeHL

# Get Nodes and Ports Parameters
with open('node_list.json') as data_file:
    data = json.load(data_file)

NODE_IMET = data["nodes"]["xbee"]
NODE_OBC = data["nodes"]["obc"]
CSP_PORT_APPS = data["ports"]["telemetry"]

#define commands
SEND_DATA = "send_xbee_data"
SEND_SUN_DATA = "send_sun_data"

class xbeeComInterface:
    def __init__(self):
        # sensor arguments
        #com args
        self.node = chr(int(NODE_IMET)).encode("ascii", "replace")
        self.node_dest = NODE_OBC
        self.port_csp = CSP_PORT_APPS
        self.prompt = "[node({}) port({})] <message>: "
        # xbee-xq interface
        self.xbee_hl =  xBeeHL(port = '/dev/xbee')

    def console(self, ip="localhost", in_port_tcp=8002, out_port_tcp=8001):
        """ Send messages to node """
        ctx = zmq.Context()
        pub = ctx.socket(zmq.PUB)
        sub = ctx.socket(zmq.SUB)
        sub.setsockopt(zmq.SUBSCRIBE, self.node)
        pub.connect('tcp://{}:{}'.format(ip, out_port_tcp))
        sub.connect('tcp://{}:{}'.format(ip, in_port_tcp))
        print('Start Xbee Intreface as node: {}'.format(int(codecs.encode(self.node, 'hex'), 16)))

        while True:
            frame = sub.recv_multipart()[0]
            header_a = []
            for byte in frame[1:5]:
                byte_int = int(codecs.encode(byte, 'hex'), 16)
                byte_hex = hex(byte_int)
                header_a.append(byte_hex[2:])
            #header_a = ["{:02x}".format(int(i)) for i in frame[1:5]]
            header = "0x"+"".join(header_a[::-1])
            data = frame[5:]
            try:
                csp_header = parse_csp(header)
            except:
                csp_header = ""
            data = data[:-1]
            print('\nMON:', frame)
            print('\tHeader: {},'.format(csp_header))
            print('\tData: {}\n'.format(data))
            cmd = data.decode("ascii", "replace")
            #print(cmd)
            # try:
            if(cmd==SEND_DATA):
                print('\nSending Image:')
                #read file
                list_of_files = glob.glob('/home/pi/test_pictures/*.jpg')
                last_file = os.path.split(max(list_of_files,key=os.path.getctime))[1]
                f_hl = open('/home/pi/test_pictures/'+last_file,"r")
                self.xbee_hl.xbee_tx('File_transfer\n')
                f_hl2=f_hl.read()
                time.sleep(1)
                for x in f_hl2:
                    self.xbee_hl.xbee_tx(x)
                time.sleep(1)
                self.xbee_hl.xbee_tx('end_file\n')
                f_hl.close()
                print('\nImage Sent:')
            elif(cmd==SEND_SUN_DATA):
                print('\nSending Image:')
                #read file
                list_of_files = glob.glob('/home/pi/sun_pictures/*.jpg')
                last_file = os.path.split(max(list_of_files,key=os.path.getctime))[1]
                f_hl = open('/home/pi/sun_pictures/'+last_file,"r")
                self.xbee_hl.xbee_tx('File_transfer\n')
                f_hl2=f_hl.read()
                time.sleep(1)
                for x in f_hl2:
                    self.xbee_hl.xbee_tx(x)
                time.sleep(1)
                self.xbee_hl.xbee_tx('end_file\n')
                f_hl.close()
                print('\nImage Sent:')
            else:
                print("unknown command")


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

    xbee_handler = xbeeComInterface()

    tasks = []

    if args.ncon:
        # Create a console socket
        console_th = Thread(target=xbee_handler.console, args=(args.ip, args.out_port, args.in_port))
        # console_th.daemon = True
        tasks.append(console_th)
        console_th.start()

    for th in tasks:
        th.join()
