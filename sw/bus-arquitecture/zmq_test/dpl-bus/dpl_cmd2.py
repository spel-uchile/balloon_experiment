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
    def __init__(self):
        # com parameters
        self.foo = 0
    def publish_data(port="8001", ip="localhost", origin=10):
        """ Send messages to node """
        ctx = zmq.Context()
        sock = ctx.socket(zmq.PUB)
        # sock.connect('tcp://{}:{}'.format(ip, port))
        # sock.connect ('tcp://localhost:8001')
        sock.bind("tcp://*:8001")
        node = '4'
        port = 10

        while True:
            try:
                print("Seleccion de acciones")
                print("1 Cerrar actuador lineal")
                print("2 Abrir actuador lineal")
                print("3 Servo en 0")
                print("4 Servo en 180")
                accion = input("Funcion a aplicar ")
                sock.send("%s %s" % (node, accion))
            except Exception as e:
                raise(e)

            time.sleep(0.25)

if __name__ == '__main__':
    dpl_cmd = DplCmdInterface()

    tasks = []

    # Create a console socket
    con_th = Thread(target=dpl_cmd.publish_data)
    con_th.daemon = True
    tasks.append(con_th)
    con_th.start()

    for th in tasks:
        th.join()