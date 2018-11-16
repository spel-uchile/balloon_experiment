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

#get gps data
for row_gps in c.execute('SELECT * FROM gps_table ORDER BY idx DESC LIMIT 1'):
    #print row_gps
    gps_id = row_gps[0]
    system_time = row_gps[1]
    gps_time = row_gps[2]
    gps_latitude = row_gps[3]
    gps_longitude = row_gps[4]
    gps_height = row_gps[5]
    gps_velocity_x = row_gps[6]
    gps_velocity_y = row_gps[7]
    gps_satellites = row_gps[8]
    gps_mode = row_gps[9]
    phase = row_gps[10]
    phase_str = get_phase(phase)

#get bmp data
for row_bmp in c.execute('SELECT * FROM pressure_table ORDER BY idx DESC LIMIT 1'):
    #print row_bmp
    bmp_id = row_bmp[0]
    bmp_pressure = row_bmp[2]
    bmp_temperature = row_bmp[3]
    bmp_altitude = row_bmp[4]

#get dpl data
for row_dpl in c.execute('SELECT * FROM deploy_table ORDER BY idx DESC LIMIT 1'):
    #print row_dpl
    dpl_id = row_dpl[0]
    dpl_lineal_state = row_dpl[2]
    dpl_servo_state = row_dpl[3]

#get system data
for row in c.execute('SELECT value FROM dat_system WHERE idx="2";'):
    sys_min_alive = row[0]

#get system data
for row in c.execute('SELECT value FROM dat_system WHERE idx="4";'):
    sys_reset_counter = row[0]

#check gps data
try:
    type(gps_id)
    type(system_time)
    type(gps_time)
    type(gps_latitude)
    type(gps_longitude)
    type(gps_height)
    type(gps_velocity_x)
    type(gps_velocity_y)
    type(gps_satellites)
    type(gps_mode)
    type(phase)
    type(phase_str)
except:#fill with error value
    gps_id = -1
    system_time = "-1"
    gps_time = "-1"
    gps_latitude = -1
    gps_longitude = -1
    gps_height = -1
    gps_velocity_x = -1
    gps_velocity_y = -1
    gps_satellites = -1
    gps_mode = -1
    phase = -1
    phase_str = "-1"
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
try:
    type(dpl_id)
    type(dpl_lineal_state)
    type(dpl_servo_state)
except:#fill with error value
    dpl_id = -1
    dpl_lineal_state = -1
    dpl_servo_state = -1
#check system data
try:
    type(sys_min_alive)
except:#fill with error value
    sys_min_alive = -1
#check system data
try:
    type(sys_reset_counter)
except:#fill with error value
    sys_reset_counter = -1

print("%s %s %.3f %.3f %.3f %.3f %.3f %.3f %d %d %.3f %.3f %d %d %s %d %d" % (system_time, gps_time, gps_latitude, gps_longitude, gps_height, gps_velocity_x, gps_velocity_y, gps_satellites, gps_mode, bmp_temperature, bmp_pressure, bmp_altitude, dpl_lineal_state, dpl_servo_state, phase_str, sys_reset_counter, sys_min_alive))