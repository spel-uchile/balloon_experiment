#!/usr/bin/python

__author__ = 'gdiaz'

# APRS TEST

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
import argparse
import re
import serial

from threading import Thread
from time import sleep
from struct import *

sys.path.append('../')

from nodes.node_list import NODE_DPL, NODE_DPL_CMD, CSP_PORT_APPS

class DplCmdInterface:
    def __init__(self):
        # ctrl params
        self.action = 0
        #com args
        self.node = chr(int(NODE_DPL_CMD)).encode("ascii", "replace")
        # self.node_dest = chr(int(NODE_DPL)).encode("ascii", "replace")
        self.node_dest = NODE_DPL
        self.port_csp = CSP_PORT_APPS
        self.prompt = "[node({}) port({})] <message>: "
        # aprs params
        self.TEST_FRAME = "\xc0\x00\x48\x65\x6c\x6c\x6f\x20\x74\x68\x69\x73\x20\x69\x73\x20\x74\x68\x65\x20\x45\x6e\x74\x65\x72\x70\x72\x69\x73\x65\xc0"
        self.INFO_MSG = "Hello this is the Enterprise a radiosonde of research and development."

    def test_data(self):

        latitude = -33.5422
        longitude = -70.6340
        time_utc = 123.456
        fix_time = 789.012
        altitude_gps = 600.123
        speed_horizontal =  0.123
        speed_vertical = 0.456

        temperature = 20.45
        pressure = 900.234
        altitude_atms = 607.234

        lineal_state = 0
        servo_state = 1

        info = "Hello this is the Enterprise a radiosonde of research and development."

        data = pack('ffffffffffbb', 
            latitude, longitude, time_utc, fix_time, altitude_gps, speed_horizontal, speed_vertical,
            temperature, pressure, altitude_atms,
            lineal_state, servo_state)

        # print str(data)
        print("%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %d %d" % (latitude, longitude, time_utc, fix_time, altitude_gps, speed_horizontal, speed_vertical, temperature, pressure, altitude_atms, lineal_state, servo_state))


    def console(self, ip="localhost", in_port_tcp=8002, out_port_tcp=8001):
        """ Send messages to node """
        ctx = zmq.Context()
        sub = ctx.socket(zmq.SUB)
        sub.setsockopt(zmq.SUBSCRIBE, self.node)
        sub.connect('tcp://{}:{}'.format(ip, in_port_tcp))
        print("Start APRS Intreface")

        while True:
            # frame = sub.recv_multipart()[0]
            # header_a = ["{:02x}".format(i) for i in frame[1:5]]
            # header = "0x"+"".join(header_a[::-1])
            # data = frame[5:]
            # try:
            #     csp_header = parse_csp(header)
            # except:
            #     csp_header = ""
            # print('\nMON:', frame)
            # print('\tHeader: {},'.format(csp_header))
            # print('\tData: {}'.format(data))

            # Test data
            data = self.test_data()
            kiss_frame = "\xc0\x00"+data+self.INFO_MSG+"\xc0"
            
            # send data to APRS by kiss protocol
            try:
                self.aprs_kiss.write(kiss_frame)
            except Exception as e:
                pass
            time.sleep(5)

def get_parameters():
    """ Parse command line parameters """
    parser = argparse.ArgumentParser()

    parser.add_argument("-n", "--node", default=10, help="Node address")
    parser.add_argument("-d", "--ip", default="localhost", help="Hub IP address")
    parser.add_argument("-i", "--in_port", default="8001", help="Hub Input port")
    parser.add_argument("-o", "--out_port", default="8002", help="Hub Output port")
    parser.add_argument("--nmon", action="store_false", help="Disable monitor task")
    parser.add_argument("--ncon", action="store_false", help="Disable console task")

    return parser.parse_args()

if __name__ == '__main__':
    # Get arguments
    args = get_parameters()

    dpl_cmd = DplCmdInterface()
    dpl_cmd.test_data()

    # tasks = []

    # Create a console socket
    # console_th = Thread(target=dpl_cmd.console, args=(args.ip, args.out_port, args.in_port))
    # console_th.daemon = True
    # tasks.append(console_th)
    # console_th.start()

    # for th in tasks:
    #     th.join()
