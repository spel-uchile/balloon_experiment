#!/usr/bin/python

__author__ = 'gdiaz'

# DPL COM INTERFACE

"""Provides a high level interface over ZMQ for dpl data exchange.
"""

"""Description
    DPL control: node1

    console: read cmd from stdio and send to node1

    cmd(stdio)-->console[PUB]-> node1

"""

import zmq
import sys
import time

from threading import Thread
from time import sleep

#list of commands
OPEN_LA = 1
CLOSE_LA = 2
OPEN_SA = 3
CLOSE_SA = 4

class DplCmdInterface:
    def __init__(self):
        # com parameters
        self.action = "none"
    def action_list(self):
        print("Seleccion de acciones")
        print(str(OPEN_LA) + ": Cerrar actuador lineal")
        print(str(CLOSE_LA) + ": Abrir actuador lineal")
        print(str(OPEN_SA) + ": Servo en 0")
        print(str(CLOSE_SA) + ": Servo en 180")

    def console(self, port="8001", ip="localhost", origin=10):
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
                self.action_list()
                self.action = input("Accion a ejecutar: ")
                sock.send("%s %s" % (node, self.action))
            except Exception as e:
                print("Comando no existe. Ver lista de comandos.")

            time.sleep(0.25)

if __name__ == '__main__':
    dpl_cmd = DplCmdInterface()

    tasks = []

    # Create a console socket
    console_th = Thread(target=dpl_cmd.console)
    console_th.daemon = True
    tasks.append(console_th)
    console_th.start()

    for th in tasks:
        th.join()