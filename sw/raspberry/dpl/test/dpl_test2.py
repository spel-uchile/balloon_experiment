"""from smbus2 import SMBusWrapper

with SMBusWrapper(1) as bus:
    # Write a byte to address 80, offset 0
    #bus.write_byte_data(0x06, ord('R'), 0)
    b = bus.read_byte_data(0x06, 0)
    print(b)
"""


from smbus2 import SMBus

bus = SMBus(1)
state = bus.read_byte_data(0x06, 0)
print(state)