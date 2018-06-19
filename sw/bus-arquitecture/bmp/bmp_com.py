#!/usr/bin/python

__author__ = 'gdiaz'

# BMP180 ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
    BMP comunication: node1

    console:  send data to node1

    data[bmp]-->console[PUB]-> node1

"""

import zmq
import sys
import time

from threading import Thread
from time import sleep

import Adafruit_BMP.BMP085 as BMP085

sys.path.append('../')

from nodes.node_list import NODE_DATA_BMP, PORT_DATA_BMP

class BmpComInterface:
    def __init__(self):
        # arguments stuff
        self.sensor_bmp = BMP085.BMP085()

    def test_method(self, cmd):
        print "rcv from node: "+cmd

    def console(self, port=PORT_DATA_BMP, ip="localhost", node=NODE_DATA_BMP):
        """ Send messages to node """
        ctx = zmq.Context(1)
        sock = ctx.socket(zmq.PUB)
        sock.bind('tcp://{}:{}'.format(ip, port))
        print "sending data to node:"+str(node)

        while True:
            try:
                if True:#TODO: check if data is valid
                    sock.send("%s %0.2f %0.2f %0.2f" % (node, self.sensor_bmp.read_temperature(), self.sensor_bmp.read_pressure(), self.sensor_bmp.read_altitude()))
                    print node, self.sensor_bmp.read_temperature(), self.sensor_bmp.read_pressure(), self.sensor_bmp.read_altitude()
            except Exception as e:
                raise(e)
            time.sleep(1) #TODO:check this time

if __name__ == '__main__':
    bmp = BmpComInterface()

    tasks = []

    # Create a console socket
    console_th = Thread(target=bmp.console, args=(PORT_DATA_BMP, "*", NODE_DATA_BMP))
    # console_th.daemon = True
    tasks.append(console_th)
    console_th.start()

    for th in tasks:
        th.join()
