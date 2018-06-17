#!/usr/bin/python

__author__ = 'gdiaz'

# ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
    TEST comunication: node1 & node2

    commands: read cmds from node1 and execute cmd
    console:  send data[stdio] to node2

                              -> node1 -> commands[SUB]-->method[stdout]
    data[stdio]-->console[PUB]-> node2

"""

import zmq
import sys
import time

from threading import Thread
from time import sleep

class NodeComInterface:
    def __init__(self):
        # com parameters
        self.data = 0

    def test_method(self, cmd):
        print "rcv from node: "+cmd

    def commands(self, port="8001", ip="localhost", node='4'):
        """ Read messages from node(s) """
        # if node != b'':
        #     node = chr(int(node)).encode("ascii", "replace")
        node = '1'
        ctx = zmq.Context()
        sock = ctx.socket(zmq.SUB)
        sock.setsockopt(zmq.SUBSCRIBE, node)
        # sock.connect('tcp://{}:{}'.format(ip, port))
        sock.connect ('tcp://localhost:8001')
        print "listen commands from node:"+str(node)

        while True:
            # cmd = sock.recv_multipart()[0]
            cmd = sock.recv()
            self.test_method(cmd[2])

    def console(self, port="8002", ip="localhost", origin=10):
        """ Send messages to node """
        ctx = zmq.Context(1)
        sock = ctx.socket(zmq.PUB)
        # sock.connect('tcp://{}:{}'.format(ip, port))
        sock.connect('tcp://localhost:8002')
        node = '2'
        port = 10
        print "sending data to node:"+str(node)

        while True:
            try:
                sock.send("%s %d" % (node, self.data))
            except Exception as e:
                raise(e)
            print "send to node: "+str(self.data)
            sleep(2)

if __name__ == '__main__':
    node = NodeComInterface()

    tasks = []

    # Start commands thread
    cmds_th = Thread(target=node.commands)
    # cmds_th.daemon = True
    tasks.append(cmds_th)
    cmds_th.start()

    # Create a console socket
    console_th = Thread(target=node.console)
    # console_th.daemon = True
    tasks.append(console_th)
    console_th.start()

    for th in tasks:
        th.join()