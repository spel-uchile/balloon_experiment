import sys
import sqlite3
conn = sqlite3.connect('/home/pi/Spel/suchai.db')
c = conn.cursor()

def get_phase(phase):
    if phase == 0:
        return "A0"
    elif phase == 1:
        return "A"
    elif phase == 2:
        return "B"
    elif phase == 3:
        return "B1"
    elif phase == 4:
        return "B2"
    elif phase == 5:
        return "C"
    elif phase == 6:
        return "C1"
    else:
        return "X"

#get phase data
for row_phase in c.execute('SELECT * FROM gps_table ORDER BY idx DESC LIMIT 1'):
    system_time = row_phase[1]
    phase = row_phase[10]
    phase_str = get_phase(phase)

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

#get system data
for row in c.execute('SELECT value FROM dat_system WHERE idx="2";'):
    sys_min_alive = row[0]

#check gps data
try:
    type(system_time)
    type(phase)
    type(phase_str)
except:#fill with error value
    system_time = "-1"
    phase = -1
    phase_str = "-1"

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

#check system data
try:
    type(sys_min_alive)
except:#fill with error value
    sys_min_alive = -1

print("%d %d %d %s %s %d %d %d %d %s %s %d" % (imet_pressure, imet_temperature, imet_humidity, imet_date, imet_time, imet_latitude, imet_longitude, imet_altitude, imet_satellites, system_time,  phase_str, sys_min_alive))