#!/usr/bin/python

__author__ = 'gdiaz'

# GPS ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
    GPS comunication: node1

    console:  send data to node1

    data[gps]-->console[PUB]-> node1

"""

import zmq
import sys
import time

from threading import Thread
from time import sleep
from gps import *

class GpsComInterface:
    def __init__(self):
        # gps arguments
        self.gps_handler = gps(mode=WATCH_ENABLE) #starting the stream of info

    def test_method(self, cmd):
        print "rcv from node: "+cmd

    def console(self, port="8003", ip="localhost", origin=10):
        """ Send messages to node """
        ctx = zmq.Context(1)
        sock = ctx.socket(zmq.PUB)
        # sock.connect('tcp://{}:{}'.format(ip, port))
        sock.connect('tcp://localhost:8003')
        node = '3'
        port = 10
        print "sending data to node:"+str(node)

        while True:
            try:
                if True:#TODO: check if data is valid
                    self.socket.send("%s %4.4f %4.4f %s" % (node, self.gps_handler.fix.latitude, self.gps_handler.fix.longitude, str(self.gps_handler.utc)))
                    print self.gps_handler.fix.latitude, self.gps_handler.fix.longitude, self.gps_handler.utc
                self.gps_handler.next()
            except Exception as e:
                raise(e)
            print "send to node: "+str(self.data)
            # time.sleep(1) #TODO:check this time

if __name__ == '__main__':
    gps = GpsComInterface()

    tasks = []

    # Create a console socket
    console_th = Thread(target=gps.console)
    # console_th.daemon = True
    tasks.append(console_th)
    console_th.start()

    for th in tasks:
        th.join()