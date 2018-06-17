#!/usr/bin/python

__author__ = 'gdiaz'

# Logger ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
    TEST comunication: node1

    data: read data from node1 and save to file

                              -> node1 -> data[SUB]-->file[stdout]

"""

import zmq
import sys
import time

from threading import Thread
from time import sleep

class GpsLoggInterface:
    def __init__(self):
        # com parameters
        self.data = 0

    def test_method(self, cmd):
        print "rcv from node: "+cmd

    def data(self, port="8002", ip="localhost", node='2'):
        """ Read messages from node(s) """
        # if node != b'':
        #     node = chr(int(node)).encode("ascii", "replace")
        node = '2'
        ctx = zmq.Context()
        sock = ctx.socket(zmq.SUB)
        sock.setsockopt(zmq.SUBSCRIBE, node)
        # sock.connect('tcp://{}:{}'.format(ip, port))
        sock.connect ('tcp://localhost:8002')
        print "listen data from node:"+str(node)

        while True:
            # cmd = sock.recv_multipart()[0]
            cmd = sock.recv()
            self.test_method(cmd[2:])

if __name__ == '__main__':
    gps_logg = GpsLoggInterface()

    tasks = []

    # Start data thread
    cmds_th = Thread(target=gps_logg.data)
    # cmds_th.daemon = True
    tasks.append(cmds_th)
    cmds_th.start()

    for th in tasks:
        th.join()