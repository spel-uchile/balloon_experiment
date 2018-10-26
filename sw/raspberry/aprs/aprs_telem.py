#!/usr/bin/python

__author__ = 'gdiaz'

# APRS TEST

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
    BMP comunication: node1

    console:  send data to node1

    data[bmp]-->console[PUB]-> node1

"""

import sys
import time
import re
import argparse

from threading import Thread
from time import sleep

import Adafruit_BMP.BMP085 as BMP085
from gpiozero import *
from gps import *

sys.path.append('../')

class APRSTEST:
    def __init__(self):
        # sensor arguments
        self.sensor_bmp = BMP085.BMP085()
        self.temperature = 0        #float
        self.pressure = 0           #float
        self.altitude_atms = 0           #float
        #Linear Actuator Validation Pin
        self.mag_int1 = Button(4)
        #Servo magnet
        self.mag_int2 = Button(17)
        #states
        self.lineal_state = 0   #0:cerrado/extendido, 1:abierto/retraido
        self.servo_state = 0    #0:meaning1, 1:meaning2
        # gps arguments
        self.gps_handler = gps(mode=WATCH_ENABLE) #starting the stream of info
        
        self.latitude = 0           #float
        self.longitude = 0          #float
        self.time_utc = 0           #str
        self.fix_time = 0           #float
        self.altitude_gps = 0           #float
        self.speed_horizontal = 0   #float
        self.speed_vertical = 0     #float

    def update_bmp(self):
        self.temperature = self.sensor_bmp.read_temperature()
        self.pressure = self.sensor_bmp.read_pressure()
        self.altitude = self.sensor_bmp.read_altitude()

    def update_dpl(self):
        self.lineal_state = self.mag_int1.is_pressed
        self.servo_state = self.mag_int2.is_pressed

    def check_nan(self, num, id):
        #print(type(num))
        #print(num)
        try:
            if math.isnan(num):
                return -1
            if num == None:
                return -1
        except:
            #print num, id
            if num == None:
                return -1
            if id==3:#TODO: chech this!!!
                return -1
            return num

    def update_gps(self):
        self.latitude = self.check_nan(self.gps_handler.fix.latitude, 1)
        self.longitude = self.check_nan(self.gps_handler.fix.longitude, 2)
        self.time_utc = self.gps_handler.utc
        self.fix_time = self.check_nan(self.gps_handler.fix.time, 3)
        self.altitude = self.check_nan(self.gps_handler.fix.altitude, 4)
        self.speed_horizontal = self.check_nan(self.gps_handler.fix.speed, 5)
        self.speed_vertical = self.check_nan(self.gps_handler.fix.climb, 6)
        #print(self.gps_handler.utc, self.gps_handler.fix.time)
        #time.sleep(0.1)
        self.gps_handler.next()
        if self.latitude == None:
            self.latitude = -1
        if self.longitude == None:
            self.longitude = -1

        #print self.latitude

if __name__ == '__main__':
    # Get arguments

    aprs = APRSTEST()

    aprs.update_bmp()
    aprs.update_dpl()
    aprs.update_gps()

    print("%.3f %.3f %s %.3f %.3f %.3f %.3f %.3f %.3f %.3f %d %d" % (aprs.latitude, aprs.longitude, aprs.time_utc, aprs.fix_time, aprs.altitude_gps, aprs.speed_horizontal, aprs.speed_vertical, aprs.temperature, aprs.pressure, aprs.altitude_atms, aprs.lineal_state, aprs.servo_state))   
