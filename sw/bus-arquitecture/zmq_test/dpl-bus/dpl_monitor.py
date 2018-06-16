#!/usr/bin/python

__author__ = 'gdiaz'

# GPS subsciber

"""Provides a high level interface over ZMQ for gps data exchange.
"""

import zmq
import sys

from threading import Thread

class DplMonitor:
    def __init__(self, port="8004", ip="localhost", node=b''):
        # com parameters
        self.running = False
        self.port = port
        self.ip = ip
        self.node = node
        # zmq arguments
        self.context = zmq.Context()
        self.socket = self.context.socket(zmq.SUB)

    def initialize(self):
        # zmq
        print "Listen Publisher"
        self.socket.connect ("tcp://localhost:%s" % self.port)

    def start(self):
        # Create subs, services, publishers, threads
        self.running = True
        #subscribers
        self.topic = '/dpl_data'
        self.socket.setsockopt(zmq.SUBSCRIBE, self.topic)

        self.sub_th = Thread(target=self.monitor).start()

    def stop(self):
        print "\nKilling Thread..."
        self.running = False
        self.sub_th.join()

    def monitor(self):
        while self.running:
            try:
                data = self.socket.recv()
                if True:#TODO: check if data is valid
                    print data
            except KeyboardInterrupt:
                self.stop()
if __name__ == '__main__':
    gps_monitor = DplMonitor()
    gps_monitor.initialize()
    gps_monitor.start()
    # gps_monitor.monitor()
