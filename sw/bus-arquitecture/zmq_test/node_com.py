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

from node_list import NODE_CMD,PORT_CMD, NODE_DATA, PORT_DATA

class NodeComInterface:
    def __init__(self):
        # com parameters
        self.data = 0

    def test_method(self, cmd):
        print "rcv from node: "+cmd

    def commands(self, port=PORT_CMD, ip="localhost", node=NODE_CMD):
        """ Read messages from node(s) """
        ctx = zmq.Context()
        sock = ctx.socket(zmq.SUB)
        sock.setsockopt(zmq.SUBSCRIBE, node)
        sock.connect('tcp://{}:{}'.format(ip, port))
        print "listen commands from node:"+str(node)

        while True:
            # cmd = sock.recv_multipart()[0]
            cmd = sock.recv()
            self.test_method(cmd[2])

    def console(self, port=PORT_DATA, ip="localhost", node=NODE_DATA):
        """ Send messages to node """
        ctx = zmq.Context(1)
        sock = ctx.socket(zmq.PUB)
        sock.connect('tcp://{}:{}'.format(ip, port))
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
    cmds_th = Thread(target=node.commands, args=(PORT_CMD, "localhost", NODE_CMD))
    # cmds_th.daemon = True
    tasks.append(cmds_th)
    cmds_th.start()

    # Create a console socket
    console_th = Thread(target=node.console, args=(PORT_DATA, "localhost", NODE_DATA))
    # console_th.daemon = True
    tasks.append(console_th)
    console_th.start()

    for th in tasks:
        th.join()