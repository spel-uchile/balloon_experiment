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
import re

from threading import Thread
from gpiozero import *
from time import sleep

sys.path.append('../')

from nodes.node_list import NODE_CMD_DPL,PORT_CMD_DPL, NODE_DATA_DPL, PORT_DATA_DPL

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
        #data args
        self.prompt = "[node({}) port({})] <message>: "

    def start(self):
        self.enable_lineal.off()
        self.ln_sgnl1.off()
        self.ln_sgnl2.off()

        self.en_sr_so.off()
        self.srvo_sgnl.off()
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
        accion = int(cmd)
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
        strt = self.start()



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
            self.execute(cmd[2])

    def console(self, port=PORT_DATA_DPL, ip="localhost", node_dest=NODE_HUB, origin_node=NODE_DATA_DPL):
        """ Send messages to node """
        ctx = zmq.Context(1)
        sock = ctx.socket(zmq.PUB)
        sock.bind('tcp://{}:{}'.format(ip, port))

        # build msg
        #          Prio   SRC   DST    DP   SP  RES HXRC
        header = "{:02b}{:05b}{:05b}{:06b}{:06b}00000000"

        prompt = self.prompt.format(node_dest, port)
        # Get CSP header and data
        hdr = header.format(1, int(origin_node), node_dest, port, 63)

        # Build CSP message
        hdr_b = re.findall("........",hdr)[::-1]
        # print("con:", hdr_b, ["{:02x}".format(int(i, 2)) for i in hdr_b])
        hdr = bytearray([int(i,2) for i in hdr_b])

        while True:
            self.state()
            print("Actuador lineal " + str(int(self.lineal_state)))
            print("Servo " + str(int(self.servo_state)))
            # join data
            data = " ".join([self.lineal_state, self.servo_state])
            msg = bytearray([node_dest,]) + hdr + bytearray(data, "ascii")
            try:
                sock.send(msg)
            except Exception as e:
                pass
            time.sleep(0.25)


def get_parameters():
    """ Parse command line parameters """
    parser = argparse.ArgumentParser()

    parser.add_argument("-n", "--node", default=10, help="Node address")
    parser.add_argument("-d", "--ip", default="localhost", help="Hub IP address")
    parser.add_argument("-i", "--in_port", default="8001", help="Input port")
    parser.add_argument("-o", "--out_port", default="8002", help="Output port")
    parser.add_argument("--nmon", action="store_false", help="Disable monitor task")
    parser.add_argument("--ncon", action="store_false", help="Disable console task")

    return parser.parse_args()

if __name__ == '__main__':
    # Get arguments
    args = get_parameters()

    dpl_com = DplComInterface()

    tasks = []

    if args.nmon:
        # Start monitor thread
        commands_th = Thread(target=dpl_com.commands, args=(args.out_port, args.ip, args.node))
        # commands_th.daemon = True
        tasks.append(commands_th)
        commands_th.start()

    if args.ncon:
        # Create a console socket
        console_th = Thread(target=dpl_com.console, args=(args.in_port, args.ip, args.node))
        # console_th.daemon = True
        tasks.append(console_th)
        console_th.start()

    for th in tasks:
        th.join()
