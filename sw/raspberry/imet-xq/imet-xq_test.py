#!/usr/bin/python3

__author__ = 'gdiaz'

# iMet-XQ Test Script

import serial

from threading import Thread
from time import sleep

class iMetXQComInterface:
    def __init__(self):
        # sensor arguments
        # imet-xq interface
        self.serial_port = serial.Serial("/dev/ttyUSB0", "57600", timeout=5)
        self.temperature = 0
        self.pressure = 0
        self.humidity = 0

    def update_data(self):
        while True:
            data = self.serial_port.read(81)
            pressure = data[5:12]
            temperature = data[13:18]
            humidity = data[19:24]
            date = data[25:35]
            time = data[36:44]
            latitude = data[45:56]
            longitude = data[57:68]
            altitude = data[69:78]
            satellites = data[79:81]

            pressure_ = int(pressure)
            temperature_ = int(temperature)
            humidity_ = int(humidity)
            date_ = date
            time_ = time
            latitude_ = latitude
            longitude_ = longitude
            altitude_ = int(altitude)
            satellites_ = int(satellites)

            print(data)
            # print("pressure = "+ pressure)
            # print("temperature = "+ temperature)
            # print("humidity = "+ humidity)
            # print("date = "+ date)
            # print("time = "+ time)
            # print("latitude = "+ latitude)
            # print("longitude = "+ longitude)
            # print("altitude = "+ altitude)
            # print("satellites = "+ satellites)
            print("pressure = "+ str(pressure_))
            print("temperature = "+ str(temperature_))
            print("humidity = "+ str(humidity_))
            print("date = "+ str(date_))
            print("time = "+ str(time_))
            print("latitude = "+ str(latitude_))
            print("longitude = "+ str(longitude_))
            print("altitude = "+ str(altitude_))
            print("satellites = "+ str(satellites_))

if __name__ == '__main__':

    bmp = iMetXQComInterface()

    while True:
        bmp.update_data()