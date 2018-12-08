#!/usr/bin/python3

__author__ = 'gdiaz'

# SSTV ZMQ COM INTERFACE

"""Provides a high level interface over ZMQ for data exchange.
"""

"""Description
"""

import zmq
import sys
import time
import re
import argparse
import json
import serial

from threading import Thread
from time import sleep
import os
# import sys
# import sqlite3
# conn = sqlite3.connect('/home/pi/Spel/suchai.db')
# c = conn.cursor()
from time import gmtime, strftime

# Get Nodes and Ports Parameters
with open('node_list.json', encoding='utf-8') as data_file:
    data = json.load(data_file)

NODE_IMET = data["nodes"]["sstv"]
NODE_OBC = data["nodes"]["obc"]
CSP_PORT_APPS = data["ports"]["telemetry"]

#define commands
RUN_SSTV = "run_sstv"

class sstvComInterface:
    def __init__(self):
        # sensor arguments
        #com args
        self.node = chr(int(NODE_IMET)).encode("ascii", "replace")
        self.node_dest = NODE_OBC
        self.port_csp = CSP_PORT_APPS
        self.prompt = "[node({}) port({})] <message>: "

    def console(self, ip="localhost", in_port_tcp=8002, out_port_tcp=8001):
        """ Send messages to node """
        ctx = zmq.Context()
        pub = ctx.socket(zmq.PUB)
        sub = ctx.socket(zmq.SUB)
        sub.setsockopt(zmq.SUBSCRIBE, self.node)
        pub.connect('tcp://{}:{}'.format(ip, out_port_tcp))
        sub.connect('tcp://{}:{}'.format(ip, in_port_tcp))
        print('Start iMet-XQ Intreface as node:" {},'.format(int.from_bytes(self.node, byteorder='little')))

        while True:
            frame = sub.recv_multipart()[0]
            header_a = ["{:02x}".format(i) for i in frame[1:5]]
            header = "0x"+"".join(header_a[::-1])
            data = frame[5:]
            try:
                csp_header = parse_csp(header)
            except:
                csp_header = ""
            data = data[:-1]
            print('\nMON:', frame)
            print('\tHeader: {},'.format(csp_header))
            print('\tData: {}\n'.format(data))
            cmd = data.decode("ascii", "replace")
            # print(cmd)
            # try:
            if(cmd==RUN_SSTV):
                print('\nRunning sstv:')
                # read software minutes alive
                # for row in c.execute('SELECT value FROM dat_system WHERE idx="2";'):
                #     sys_min_alive = str(row[0])
                # #check system data
                # try:
                #     type(sys_min_alive)
                # except:#fill with error value
                #     sys_min_alive = "U"
                sys_min_alive = strftime("%Y-%m-%d_%H:%M:%S", gmtime())
                file_path = "/home/pi/Spel/sstv_img/"
                file_name = "img"+sys_min_alive+".png"
                sstv_path = "/home/pi/Spel/sstv/pisstv/"
                # take picture
                picture_cmd = "raspistill -t 1 -ex auto --width 320 --height 256 -e png -o "+file_path+file_name
                os.system(picture_cmd)
                # generate sound file from image
                gensound_cmd = sstv_path+"pisstv "+file_path+file_name+" 22050"
                os.system(gensound_cmd)
                # play sound file
                play_cmd = "sudo aplay -c2 "+file_path+file_name+".wav"
                os.system(play_cmd)


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

    sstv = sstvComInterface()

    tasks = []

    if args.ncon:
        # Create a console socket
        console_th = Thread(target=sstv.console, args=(args.ip, args.out_port, args.in_port))
        # console_th.daemon = True
        tasks.append(console_th)
        console_th.start()

    for th in tasks:
        th.join()
