import zmq
import time
import argparse
from threading import Thread

import serial
from serial.tools.list_ports import comports as listports
from serial.tools.list_ports import grep as listports_grep

serial_port = None
ctx = zmq.Context(1)

def monitor(port="8002", ip="localhost", node=b''):
    """ Read messages from node(s) """
    if node != b'':
        node = chr(int(node)).encode("ascii", "replace")

    sock = ctx.socket(zmq.SUB)
    sock.setsockopt(zmq.SUBSCRIBE, node)
    sock.connect('tcp://{}:{}'.format(ip, port))

    while True:
        frame = sock.recv_multipart()[0]
        print('MON:', frame)
        # [node][data(41)][padding (254-41)]
        data = frame[1:42]
        hdr = b"AT+SBDWT="
        tail = b"\r"
        serial_port.write(hdr+data+tail)
        serial_port.write(b"AT+SBDIX\r")


def console(port="8001", ip="localhost", to_read=255):
    """ Send messages to node """

    sock = ctx.socket(zmq.PUB)
    sock.connect('tcp://{}:{}'.format(ip, port))
    prompt = "[node({})] <message>: "
    node = 1

    while True:
        try:
            # to_read = serial_port.inWaiting()
            # if(to_read):
            data = serial_port.read(to_read)
            if (len(data)) and (not data == '\r'):
                print("SER: ", data)
                print(data)

        except UnicodeDecodeError as e:
            print(e)
            pass

        except serial.SerialException as e:
            print(e)
            pass

def get_parameters():
    """ Parse command line parameters """
    parser = argparse.ArgumentParser()

    parser.add_argument("-n", "--node", default=b'', help="Node address")
    parser.add_argument("-d", "--ip", default="localhost", help="Hub IP address")
    parser.add_argument("-i", "--in_port", default="8001", help="Input port")
    parser.add_argument("-o", "--out_port", default="8002", help="Output port")
    parser.add_argument("--nmon", action="store_false", help="Disable monitor task") 
    parser.add_argument("--ncon", action="store_false", help="Disable console task")
    parser.add_argument("dev", help="Serial port eg: /dev/tty0, /dev/ttyUSB0")
    parser.add_argument("baud", type=int, help="Baudrate eg: 115200, 500000")

    return parser.parse_args()

if __name__ == "__main__":
    # Get arguments
    args = get_parameters()
    print(args)

    tasks = []

    try:
        serial_port = serial.Serial(args.dev, args.baud, timeout=1)
    except Exception as e:
        print(e)

    if args.nmon:
        # Start monitor thread
        mon_th = Thread(target=monitor, args=(args.out_port, args.ip, args.node))
        mon_th.daemon = True
        tasks.append(mon_th)
        mon_th.start()

    if args.ncon:
        # Create a console socket
        con_th = Thread(target=console, args=(args.in_port, args.ip))
        con_th.daemon = True
        tasks.append(con_th)
        con_th.start()

    for th in tasks:
th.join()
