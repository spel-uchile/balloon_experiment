import sys
import sqlite3
import os
conn = sqlite3.connect('/home/pi/Spel/suchai.db')
c = conn.cursor()

#get imet data
for row_imet in c.execute('SELECT * FROM imet_table ORDER BY idx DESC LIMIT 1'):
    imet_pressure = row_imet[2]
    imet_temperature = row_imet[3]
    imet_humidity = row_imet[4]
    imet_date = row_imet[5]
    imet_time = row_imet[6]
    imet_latitude = row_imet[7]
    imet_longitude = row_imet[8]
    imet_altitude = row_imet[9]
    imet_satellites = row_imet[10]

#get phase data
for row_phase in c.execute('SELECT * FROM gps_table ORDER BY idx DESC LIMIT 1'):
    phase = row_phase[10]

#get system data
for row in c.execute('SELECT value FROM dat_system WHERE idx="2";'):
    sys_min_alive = row[0]

#get bmp data
for row_bmp in c.execute('SELECT * FROM pressure_table ORDER BY idx DESC LIMIT 1'):
    #print row_bmp
    bmp_id = row_bmp[0]
    bmp_pressure = row_bmp[2]
    bmp_temperature = row_bmp[3]
    bmp_altitude = row_bmp[4]

#get dpl data
for row_dpl in c.execute('SELECT * FROM deploy_table ORDER BY idx DESC LIMIT 1'):
    dpl_lineal_state = row_dpl[2]

#check dpl data
try:
    type(dpl_lineal_state)
except:#fill with error value
    dpl_lineal_state = -1

#check imet data
try:
    type(imet_pressure)
    type(imet_temperature)
    type(imet_humidity)
    type(imet_date)
    type(imet_time)
    type(imet_latitude)
    type(imet_longitude)
    type(imet_altitude)
    type(imet_satellites)
except:#fill with error value
    imet_pressure = -1
    imet_temperature = -1
    imet_humidity = -1
    imet_date = "-1"
    imet_time = "-1"
    imet_latitude = -1
    imet_longitude = -1
    imet_altitude = -1
    imet_satellites = -1

#check bmp data
try:
    type(bmp_id)
    type(bmp_pressure)
    type(bmp_temperature)
    type(bmp_altitude)
except:#fill with error value
    bmp_id = -1
    bmp_pressure = -1
    bmp_temperature = -1
    bmp_altitude = -1
#check dpl data

#check system data
try:
    type(sys_min_alive)
except:#fill with error value
    sys_min_alive = -1

#check phase data
try:
    type(phase)
except:#fill with error value
    phase = -1

#generate sequence number
sec_file = open("/tmp/seq_num.txt", "a+")
sec_str = sec_file.read()
try:
    sec_num = int(sec_str)
    sec_file.seek(0,0)
    sec_file.truncate()
    sec_file.write(str((sec_num+1)%255))
except:
    sec_file.write("1")
    sec_num = 0
#print(sec_num)

#get phase_byte
def get_byte_phase(phase):
    if phase == 0:
        return "0000000"
    elif phase == 1:
        return "0000001"
    elif phase == 2:
        return "0000010"
    elif phase == 3:
        return "0000100"
    elif phase == 4:
        return "0001000"
    elif phase == 5:
        return "0010000"
    elif phase == 6:
        return "0100000"
    elif phase == 7:
        return "1000000"
    else:
        return "1111111"

def get_bit_dpl(dpl_state):
    return(str(int(dpl_state>0)))

state_byte = get_bit_dpl(dpl_lineal_state)+get_byte_phase(phase)
#send data to direwolf
print("T#%d,%d,%d,%d,%d,%d,%s" % (sec_num, imet_pressure/1000, int(bmp_pressure)/1000, imet_temperature/100, int(bmp_temperature), int(bmp_altitude)/100, state_byte))