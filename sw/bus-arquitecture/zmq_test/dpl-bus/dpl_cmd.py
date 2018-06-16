#!/usr/bin/python

__author__ = 'gdiaz'

# GPS COM INTERFACE

"""Provides a high level interface over ZMQ for dpl data exchange.
"""

import zmq
import sys
import time

from threading import Thread
from time import sleep

class DplCmdInterface:
    def __init__(self, port="8011", ip="localhost", node=b''):
        # com parameters
        self.running = False
        self.port = port
        self.ip = ip
        self.node = node
        self.data_pub = '/dpl_data'
        self.data_sub = '/dpl_cmd' 
        # zmq arguments
        self.context = zmq.Context()
        self.socket = self.context.socket(zmq.PUB)
        

    def initialize(self):
        # zmq publisher
        self.socket.bind("tcp://*:%s" % self.port)

    def start(self):
        # Create subs, services, publishers, threads
        self.running = True
        #publishers
        self.data_pub = '/dpl_cmd'

        self.pub_th = Thread(target=self.publish_data)
        self.pub_th.start()

    def stop(self):
        print "\nKilling Thread..."
        self.running = False
        self.pub_th.join()

    def publish_data(self):
        while self.running:
            try:
                print("Seleccion de acciones")
                print("1 Cerrar actuador lineal")
                print("2 Abrir actuador lineal")
                print("3 Servo en 0")
                print("4 Servo en 180")
                accion = input("Funcion a aplicar ")
                self.socket.send("%s" % (accion))
            except KeyboardInterrupt:
                self.stop()
            time.sleep(1)

if __name__ == '__main__':
    dpl_cmd = DplCmdInterface()
    dpl_cmd.initialize()
    dpl_cmd.start() 
   #dpl_cmd.publish_data()
