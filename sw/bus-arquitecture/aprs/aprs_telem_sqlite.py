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
#print(type(system_time))
#print(type(gps_time))
#print(type(gps_latitude))
#print(type(gps_longitude))
#print(type(gps_height))
#print(type(gps_velocity_x))
#print(type(gps_velocity_y))
#print(type(gps_satellites))
#print(type(gps_mode))
#print()


for row_bmp in c.execute('SELECT * FROM pressure_table ORDER BY idx DESC LIMIT 1'):
    #print row_bmp
    bmp_id = row_bmp[0]
    bmp_pressure = row_bmp[2]
    bmp_temperature = row_bmp[3]
    bmp_altitude = row_bmp[4]

#print(str(bmp_pressure)+str(type(bmp_pressure)))
#print(str(bmp_temperature)+str(type(bmp_temperature)))
#print(str(bmp_altitude)+str(type(bmp_altitude)))
#print()

for row_dpl in c.execute('SELECT * FROM deploy_table ORDER BY idx DESC LIMIT 1'):
    #print row_dpl
    dpl_id = row_dpl[0]
    dpl_lineal_state = row_dpl[2]
    dpl_servo_state = row_dpl[3]

#get minutes alive
for row in c.execute('SELECT value FROM dat_system WHERE idx="2";'):
    sys_min_alive = row[0]

#get reset counter
for row in c.execute('SELECT value FROM dat_system WHERE idx="4";'):
    sys_reset_counter = row[0]

#print(str(dpl_lineal_state)+str(type(dpl_lineal_state)))
#print(str(dpl_servo_state)+str(type(dpl_servo_state)))

print("\x21%s %s %.3f %.3f %.3f %.3f %.3f %.3f %d %d %.3f %.3f %d %d %s %d %d" % (system_time, gps_time, gps_latitude, gps_longitude, gps_height, gps_velocity_x, gps_velocity_y, gps_satellites, gps_mode, bmp_temperature, bmp_pressure, bmp_altitude, dpl_lineal_state, dpl_servo_state, phase_str, sys_reset_counter, sys_min_alive))

#var = sys.getsizeof(system_time)+ sys.getsizeof(gps_time)+ sys.getsizeof(gps_latitude)+sys.getsizeof(gps_longitude)+sys.getsizeof(gps_height)+sys.getsizeof(gps_velocity_x)+ sys.getsizeof(gps_velocity_y)+sys.getsizeof(gps_satellites)+sys.getsizeof(gps_mode)+sys.getsizeof(bmp_temperature)+sys.getsizeof(bmp_pressure)+sys.getsizeof(bmp_altitude)+sys.getsizeof(dpl_lineal_state)+sys.getsizeof(dpl_servo_state)
#print(var)
