#!/usr/bin/python

__author__ = 'gdiaz'

# ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
    TEST control: node1

    console: read cmd from stdio and send to node1

    cmd(stdio)-->console[PUB]-> node1

"""

import zmq
import sys
import time

from threading import Thread
from time import sleep

from node_list import NODE_CMD, PORT_CMD

#list of commands
CMD1 = 1
CMD2 = 2
CMD3 = 3
CMD4 = 4

class CmdInterface:
    def __init__(self):
        # com parameters
        self.action = "none"
    def action_list(self):
        print("Seleccion de acciones")
        print(str(CMD1) + ": Breve descripcion cmd1")
        print(str(CMD2) + ": Breve descripcion cmd2")
        print(str(CMD3) + ": Breve descripcion cmd3")
        print(str(CMD4) + ": Breve descripcion cmd4")

    def console(self, port=PORT_CMD, ip="*", node=NODE_CMD):
        """ Send messages to node """
        ctx = zmq.Context()
        sock = ctx.socket(zmq.PUB)
        sock.bind("tcp://{}:{}".format(ip, port))
        print "sending cmds to node:"+str(node)

        while True:
            try:
                self.action_list()
                self.action = input("Comando a ejecutar: ")
                sock.send("%s %s" % (node, self.action))
            except Exception as e:
                print("Comando no existe. Ver lista de comandos.")

            time.sleep(0.25)

if __name__ == '__main__':
    node_cmd = CmdInterface()

    tasks = []

    # Create a console socket
    console_th = Thread(target=node_cmd.console, args=(PORT_CMD, "*", NODE_CMD))
    console_th.daemon = True
    tasks.append(console_th)
    console_th.start()

    for th in tasks:
        th.join()