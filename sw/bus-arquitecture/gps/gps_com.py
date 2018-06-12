#!/usr/bin/python

__author__ = 'gdiaz'

# GPS COM INTERFACE

"""Provides a high level interface over ZMQ for gps data exchange.
"""

import zmq
import sys
import time

from threading import Thread
from gps import *

class GpsComInterface:
    def __init__(self, port="8002", ip="localhost", node=b''):
        # com parameters
        self.running = False
        self.port = port
        self.ip = ip
        self.node = node
        self.data_pub = '/gps_data'
        # gps arguments
        self.gps_hd = gps(mode=WATCH_ENABLE) #starting the stream of info
        # zmq arguments
        self.context = zmq.Context()
        self.socket = self.context.socket(zmq.PUB)

    def initialize(self):
        # zmq publisher
        self.socket.bind("tcp://*:%s" % self.port)

    def start(self):
        # Create subs, services, publishers, threads
        self.running = True
        #subscribers
        self.command_sub = '/gps_cmd'
        #publishers
        self.data_pub = '/gps_data'

        self.pub_th = Thread(target=self.publish_data)
        self.pub_th.start()

    def stop(self):
        print "\nKilling Thread..."
        self.running = False
        self.pub_th.join()

    def publish_data(self):
        while self.running:
            try:
                if True:#TODO: check if data is valid
                    self.socket.send("%s %4.4f %4.4f %s" % (self.data_pub, self.gps_hd.fix.latitude, self.gps_hd.fix.longitude, str(self.gps_hd.utc)))
                    print self.gps_hd.fix.latitude, self.gps_hd.fix.longitude, self.gps_hd.utc
                self.gps_hd.next()
                # time.sleep(5) #TODO:check this time
            except KeyboardInterrupt:
                self.stop()

if __name__ == '__main__':
    gps = GpsComInterface()
    gps.initialize()
    gps.start()
    gps.publish_data()