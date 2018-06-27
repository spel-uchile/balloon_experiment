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

from threading import Thread
from time import sleep

sys.path.append('../')

from nodes.node_list import NODE_DPL, NODE_OBC, CSP_PORT_APPS

#define commands
OPEN_LA = 1
CLOSE_LA = 2
OPEN_SA = 3
CLOSE_SA = 4
GET_DATA = 5

class DplComInterface:
    def __init__(self):
        #states
        self.state1 = 1   #0:meaning1, 1:meaning2
        self.state2 = 2    #0:meaning1, 1:meaning2
        #com args
        self.node = chr(int(NODE_DPL)).encode("ascii", "replace")
        self.node_dest = NODE_OBC
        self.port_csp = CSP_PORT_APPS
        self.prompt = "[node({}) port({})] <message>: "

    def execute(self, cmd):
        print (cmd)

    def console(self, ip="localhost", in_port_tcp=8002, out_port_tcp=8001):
        """ Send messages to node """
        ctx = zmq.Context()
        pub = ctx.socket(zmq.PUB)
        sub = ctx.socket(zmq.SUB)
        sub.setsockopt(zmq.SUBSCRIBE, self.node)
        pub.connect('tcp://{}:{}'.format(ip, out_port_tcp))
        sub.connect('tcp://{}:{}'.format(ip, in_port_tcp))

        while True:
            frame = sub.recv_multipart()[0]
            header_a = ["{:02x}".format(i) for i in frame[1:5]]
            header = "0x"+"".join(header_a[::-1])
            data = frame[5:]
            try:
                csp_header = parse_csp(header)
            except:
                csp_header = ""
            print('\nMON:', frame)
            print('\tHeader: {},'.format(csp_header))
            print('\tData: {}'.format(data))
            cmd = data[0]

            if cmd == GET_DATA:
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
                data_ = " ".join([self.state1, self.state2])
                msg = bytearray([int(self.node_dest),]) + hdr + bytearray(data_, "ascii")
                # send data to OBC node
                try:
                    pub.send(msg)
                except Exception as e:
                    pass
            else:
                # execute cmd from OBC node
                self.execute(cmd)
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
