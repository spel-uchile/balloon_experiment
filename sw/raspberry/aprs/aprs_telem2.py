import sys
import sqlite3
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

print("T#%d,%d,%d,%d,%d,%d,01101101" % (1, imet_pressure/1000, int(bmp_pressure)/1000, imet_temperature/100, int(bmp_temperature), int(bmp_altitude)/100))