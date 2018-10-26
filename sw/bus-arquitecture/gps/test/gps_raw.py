#!/usr/bin/python

__author__ = 'gdiaz'

import serial
import syslog
import time
from threading import Timer

#The following line is for serial over GPIO
# port = '/dev/ttyUSB0'
port = '/dev/ttyAMA0'

class gpsInterface(object):
    def __init__(self, serial, debug = False):
        self.gps = serial
        self.debug = debug

    def DEBUG_PRINT(self, msg_type, msg):
        if not(self.debug): return
        if msg_type == "info":
            print chr(27)+"[0;32m"+"[INFO]: "+chr(27)+"[0m" + msg
        elif msg_type == "warn":
            print chr(27)+"[0;33m"+"[WARN]: "+chr(27)+"[0m" + msg
        elif msg_type == "error":
            print chr(27)+"[0;31m"+"[ERROR]: "+chr(27)+"[0m" + msg
        elif msg_type == "alert":
            print chr(27)+"[0;34m"+"[ALERT]: "+chr(27)+"[0m" + msg
        else:
            print "NON implemented Debug print type"

    def read(self):
        data = self.gps.readline()
        self.gps.flush()
        # data = unicode(data_chr)
        # self.DEBUG_PRINT("info", data)
        print data

if __name__ == '__main__':
    gps_serial = serial.Serial(port, 9600, timeout=5)
    gps_hw = gpsInterface(gps_serial, debug =True)
    # test read
    while True:
        gps_hw.read()
    gps_serial.close()
