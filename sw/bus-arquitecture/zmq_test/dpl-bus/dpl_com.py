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
    def __init__(self, port="8009", port2="8010", ip="localhost", node=b''):
        # com parameters
        self.running = False
        self.port = port
        self.port2 = port2
        self.ip = ip
        self.node = node
        self.data_pub = '/dpl_data'
        self.data_sub = '/dpl_cmd'
        # dpl arguments
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

        # zmq arguments
        self.context = zmq.Context(1)
        self.socket = self.context.socket(zmq.PUB)
        self.context2 = zmq.Context(1)
        self.socket2 = self.context2.socket(zmq.SUB)
        self.socket2.setsockopt(zmq.SUBSCRIBE, self.data_sub)

    def initialize(self):
        # zmq publisher
        self.socket.bind("tcp://*:%s" % self.port)
        self.socket2.bind("tcp://*:%s" % self.port2)

    def start(self):
        # Create subs, services, publishers, threads
        self.running = True
        #publishers
        self.data_pub = '/dpl_data'

        #self.pub_th = Thread(target=self.publish_data)
        #self.pub_th.start()

        #self.sub_th = Thread(target=self.console)
        #self.sub_th.start()

    def stop(self):
        print "\nKilling Thread..."
        self.running = False
        #self.pub_th.join()
        #self.sub_th.join()

    def state(self):
        lineal_state = self.mag_int1.is_pressed
        servo_state = self.mag_int2.is_pressed
        return lineal_state, servo_state

    def publish_data(self):
        while self.running:
            try:
                if True:#TODO: check if data is valid
                    stt1, stt2 = self.state()
                    st1 = int(stt1)
                    st2 = int(stt2)
                    self.socket.send("%s %d %d" % (self.data_pub, st1, st2))
                    #print "Actuador lineal " + str(st1), "Servo " + str(st2)
                # time.sleep(5) #TODO:check this time
            except KeyboardInterrupt:
                self.stop()
            time.sleep(1)

    def console(self):
        while self.running:
            try:
                data = self.socket2.recv()
                accion = data[1]
                print data
                print acction
            except KeyboardInterrupt:
                self.stop()
            time.sleep(1)

if __name__ == '__main__':
    dpl = DplComInterface()
    dpl.initialize()
    dpl.start()

    pub_th = Thread(target=dpl.publish_data)
    pub_th.start()

    sub_th = Thread(target=dpl.console)
    sub_th.start()

    pub_th.join()
    sub_th.join()

    
    #dpl.publish_data()
