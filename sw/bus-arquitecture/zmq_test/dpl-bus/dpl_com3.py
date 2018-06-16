#!/usr/bin/python

__author__ = 'gdiaz'

# GPS COM INTERFACE

"""Provides a high level interface over ZMQ for dpl data exchange.
"""

import zmq
import sys
import time

from threading import Thread
from gpiozero import *
from time import sleep

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

    def state(self):
        lineal_state = self.mag_int1.is_pressed
        servo_state = self.mag_int2.is_pressed
        return lineal_state, servo_state

    def get_cmd(port="8001", ip="localhost", node='4'):
        """ Read messages from node(s) """
        # if node != b'':
        #     node = chr(int(node)).encode("ascii", "replace")
        node = '4'
        ctx = zmq.Context()
        sock = ctx.socket(zmq.SUB)
        sock.setsockopt(zmq.SUBSCRIBE, node)
        # sock.connect('tcp://{}:{}'.format(ip, port))
        sock.connect ('tcp://localhost:8001')
        print "start get_cmd"

        while True:
            print "listen get_cmd"
            # cmd = sock.recv_multipart()[0]
            cmd = sock.recv()
            print cmd[2]

    def publish_data(port="8002", ip="localhost", origin=10):
        """ Send messages to node """
        ctx = zmq.Context(1)
        sock = ctx.socket(zmq.PUB)
        # sock.connect('tcp://{}:{}'.format(ip, port))
        sock.connect('tcp://localhost:8002')
        node = 1
        port = 10

        msg = "data"

        while True:
            try:
                sock.send(msg)
            except Exception as e:
                raise(e)
            print msg
            time.sleep(0.25)

if __name__ == '__main__':
    dpl = DplComInterface()

    tasks = []

    # Start monitor thread
    mon_th = Thread(target=dpl.get_cmd)
    # mon_th.daemon = True
    tasks.append(mon_th)
    mon_th.start()

    # Create a console socket
    con_th = Thread(target=dpl.publish_data)
    # con_th.daemon = True
    tasks.append(con_th)
    con_th.start()

    for th in tasks:
        th.join()