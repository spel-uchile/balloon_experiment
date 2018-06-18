#!/usr/bin/python

__author__ = 'gdiaz'

# DPL ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for dpl data exchange.
"""

"""Description
    DPL comunication: node1 & node2

    commands: read cmds(int) from node1 and execute cmd
    console:  send state(int, int) to node2

                              -> node1 -> commands[SUB]-->method
    state-->console[PUB]-> node2

"""

import zmq
import sys
import time

from threading import Thread
from gpiozero import *
from time import sleep

sys.path.append('../')

from node_list.nodes.node_list import NODE_CMD_DPL,PORT_CMD_DPL, NODE_DATA_DPL, PORT_DATA_DPL

#define commands
OPEN_LA = 1
CLOSE_LA = 2
OPEN_SA = 3
CLOSE_SA = 4

class DplComInterface:
    def __init__(self):
        # com parameters
        #Linear Actuator Activation Pins
        self.enable_lineal = LED(20)
        self.ln_sgnl1 = LED(16)
        self.ln_sgnl2 = LED(7)
        #Linear Actuator Validation Pin
        self.mag_int1 = Button(4)
        #Servo Activation Pins
        self.en_sr_so = LED(24)
        self.srvo_sgnl = LED(23)
        #Servo PWM
        self.servo = Servo(18, initial_value=0, min_pulse_width=.544/1000, max_pulse_width=2.4/1000, frame_width=20./1000, pin_factory=None)
        #Servo magnet
        self.mag_int2 = Button(17)
        #states
        self.lineal_state = 0   #0:meaning1, 1:meaning2
        self.servo_state = 0    #0:meaning1, 1:meaning2

    def start(self):
        enable_lineal.off()
        ln_sgnl1.off()
        ln_sgnl2.off()

        en_sr_so.off()
        srvo_sgnl.off()
        return True

    def state(self):
        self.lineal_state = self.mag_int1.is_pressed
        self.servo_state = self.mag_int2.is_pressed

    def open_lineal(self):
        self.enable_lineal.on()
        self.ln_sgnl1.on()
        sleep(1)
        return True

    def close_lineal(self):
        self.enable_lineal.on()
        self.ln_sgnl2.on()
        sleep(1)
        return True

    def servo_0(self):
        self.en_sr_so.on()
        self.srvo_sgnl.on()
        sleep(1)
        self.servo.min()
        sleep(3)
        return True

    def servo_180(self):
        self.en_sr_so.on()
        self.srvo_sgnl.on()
        sleep(1)
        self.servo.max()
        sleep(3)
        return True

    def execute(self, cmd):
        strt = self.start()
        if accion == OPEN_LA:
            print("Ex: open_lineal")
            val = self.open_lineal()
        elif accion == CLOSE_LA:
            print("Ex: close_lineal")
            val = self.close_lineal()
        elif accion == OPEN_SA:
            print("Ex: servo_0")
            val = self.servo_0()
        elif accion == CLOSE_SA:
            print("Ex: servo_180")
            val = self.servo_180()
        else:
            print("Comando no existe. Ver lista de comandos.")
            val = False

    def commands(self, port=PORT_CMD_DPL, ip="localhost", node=NODE_CMD_DPL):
        """ Read messages from node(s) """
        # if node != b'':
        #     node = chr(int(node)).encode("ascii", "replace")
        node = '1'
        ctx = zmq.Context()
        sock = ctx.socket(zmq.SUB)
        sock.setsockopt(zmq.SUBSCRIBE, node)
        sock.connect('tcp://{}:{}'.format(ip, port))
        print "listen commands from node:"+str(node)

        while True:
            # cmd = sock.recv_multipart()[0]
            cmd = sock.recv()
            print "command rcv: " + cmd[2]
            self.execute(cmd)

    def console(self, port=PORT_DATA_DPL, ip="localhost", node=NODE_DATA_DPL):
        """ Send messages to node """
        ctx = zmq.Context(1)
        sock = ctx.socket(zmq.PUB)
        sock.connect('tcp://{}:{}'.format(ip, port))

        while True:
            print("Actuador lineal " + str(int(self.lineal_state)))
            print("Servo " + str(int(self.servo_state)))
            try:
                sock.send("%d %d %d" % (node, self.lineal_state, self.servo_state))
            except Exception as e:
                pass
            time.sleep(0.25)

if __name__ == '__main__':
    dpl_com = DplComInterface()

    tasks = []

    # Start monitor thread
    commands_th = Thread(target=dpl_com.commands, args=(PORT_CMD_DPL, "localhost", NODE_CMD_DPL))
    # commands_th.daemon = True
    tasks.append(commands_th)
    commands_th.start()

    # Create a console socket
    console_th = Thread(target=dpl_com.console, args=(PORT_DATA_DPL, "localhost", NODE_DATA_DPL))
    # console_th.daemon = True
    tasks.append(console_th)
    console_th.start()

    for th in tasks:
        th.join()