#!/usr/bin/python

__author__ = 'gdiaz'

# Logger ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
    BMP comunication: node1

    data: read data from node1 and save to file

                              -> node1 -> data[SUB]-->file[stdout]

"""

import zmq
import sys
import time

from threading import Thread
from time import sleep

sys.path.append('../')

from nodes.node_list import NODE_DATA_BMP, PORT_DATA_BMP

class BmpLoggInterface:
    #def __init__(self):
        # com parameters
    def test_method(self, cmd):
        print "rcv from node: "+cmd

    def data(self, port=PORT_DATA_BMP, ip="localhost", node=NODE_DATA_BMP):
        """ Read messages from node(s) """
        # if node != b'':
        #     node = chr(int(node)).encode("ascii", "replace")
        ctx = zmq.Context(1)
        sock = ctx.socket(zmq.SUB)
        sock.setsockopt(zmq.SUBSCRIBE, node)
        sock.connect('tcp://{}:{}'.format(ip, port))
        print "listen data from node:"+str(node)

        while True:
            # cmd = sock.recv_multipart()[0]
            cmd = sock.recv()
            self.test_method(cmd[2:])
            print cmd

if __name__ == '__main__':
    bmp_logg = BmpLoggInterface()

    tasks = []

    # Start data thread
    cmds_th = Thread(target=bmp_logg.data, args=(PORT_DATA_BMP, "localhost", NODE_DATA_BMP))
    #cmds_th.daemon = True
    tasks.append(cmds_th)
    cmds_th.start()

    for th in tasks:
        th.join()
