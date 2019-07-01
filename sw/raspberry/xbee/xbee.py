import serial
import time

class xBeeHL:
     TIME_BTW_CHAR=1.0

     def __init__(self, port='/dev/ttyUSB2'):
        self.ser=serial.Serial(
            port=port,
            baudrate=230400,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout = 0,
            bytesize=serial.EIGHTBITS)
        self.ser.isOpen()


     def xbee_tx(self, message):
        self.ser.write(message)
        time.sleep(self.TIME_BTW_CHAR/10000.0)

     def xbee_rx(self):
        out=''
        while self.ser.inWaiting()>0 & self.ser.inWaiting()<8:
            out +=self.ser.read(1)

        return out
