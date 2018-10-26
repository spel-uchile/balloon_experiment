#!/usr/bin/python

__author__ = 'gdiaz'

# DPL COM INTERFACE

"""Provides a high level interface over ZMQ for dpl data exchange.
"""

"""Description
    DPL control: node1

    console: read cmd from stdio and send to node1

    cmd(stdio)-->console[PUB]-> node1

"""

import zmq
import sys
import time
import argparse
import re

from threading import Thread
from time import sleep

#list of commands
from app_com import OPEN_LA, CLOSE_LA, OPEN_SA, CLOSE_SA, GET_DATA

sys.path.append('../')

from nodes.node_list import NODE_DPL, NODE_DPL_CMD, CSP_PORT_APPS

class DplCmdInterface:
    def __init__(self):
        # ctrl params
        self.action = 0
        #com args
        self.node = chr(int(NODE_DPL_CMD)).encode("ascii", "replace")
        # self.node_dest = chr(int(NODE_DPL)).encode("ascii", "replace")
        self.node_dest = NODE_DPL
        self.port_csp = CSP_PORT_APPS
        self.prompt = "[node({}) port({})] <message>: "

    def console(self, ip="localhost", in_port_tcp=8002, out_port_tcp=8001):
        """ Send messages to node """
        ctx = zmq.Context()
        pub = ctx.socket(zmq.PUB)
        pub.connect('tcp://{}:{}'.format(ip, out_port_tcp))

        while True:
            #try:
                self.action = input("cmd to App (node 2): ")
                # build msg
                #          Prio   SRC   DST    DP   SP  RES HXRC
                header_ = "{:02b}{:05b}{:05b}{:06b}{:06b}00000000"

                prompt = self.prompt.format(self.node_dest, self.port_csp)
                # Get CSP header_ and data
                #hdr = header_.format(1, 3, 2, 14, 63)
                hdr = header_.format(1, int.from_bytes(self.node, byteorder='little'), self.node_dest, self.port_csp, 63)

                # Build CSP message
                hdr_b = re.findall("........",hdr)[::-1]
                # print("con:", hdr_b, ["{:02x}".format(int(i, 2)) for i in hdr_b])
                hdr = bytearray([int(i,2) for i in hdr_b])
                # join data
                data_ = " ".join([self.action])
                msg = bytearray([int(self.node_dest),]) + hdr + bytearray(data_, "ascii")
                pub.send(msg)
                # send data to OBC node
            #    try:
            #        pub.send(msg)
             #   except Exception as e:
             #       pass
            #except Exception as e:
            #    print("Comando no existe. Ver lista de comandos.")

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

    dpl_cmd = DplCmdInterface()

    tasks = []

    # Create a console socket
    console_th = Thread(target=dpl_cmd.console, args=(args.ip, args.out_port, args.in_port))
    console_th.daemon = True
    tasks.append(console_th)
    console_th.start()

    for th in tasks:
        th.join()
