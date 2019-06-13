import sys
import sqlite3
conn = sqlite3.connect('/home/pi/Spel/suchai.db')
c = conn.cursor()

def get_phase(phase):
    if phase == 0:
        return "A0"
    elif phase == 1:
        return "A1"
    elif phase == 2:
        return "A"
    elif phase == 3:
        return "B"
    elif phase == 4:
        return "B1"
    elif phase == 5:
        return "B2"
    elif phase == 6:
        return "C"
    elif phase == 7:
        return "C1"
    else:
        return "X"

#get phase data
for row_phase in c.execute('SELECT * FROM gps_table ORDER BY idx DESC LIMIT 1'):
    system_time = row_phase[1]
    phase = row_phase[10]
    phase_str = get_phase(phase)

#get imet data
n_frame = 60
sql_query = 'SELECT * FROM imet_table ORDER BY idx DESC LIMIT ' + str(n_frame)
imet_dict = {
    'pressure' : [],
    'temperature' : [],
    'humidity' : [],
    'date' : [],
    'time' : [],
    'latitude' : [],
    'longitude' : [],
    'altitude' : [],
    'satellites' : []
}
for row_imet in c.execute(sql_query):
    imet_dict['pressure'].append(row_imet[2])
    imet_dict['temperature'].append(row_imet[3])
    imet_dict['humidity'].append(row_imet[4])
    imet_dict['date'].append(row_imet[5])
    imet_dict['time'].append(row_imet[6])
    imet_dict['latitude'].append(row_imet[7])
    imet_dict['longitude'].append(row_imet[8])
    imet_dict['altitude'].append(row_imet[9])
    imet_dict['satellites'].append(row_imet[10])

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

res_string = ''

try:
#print(len(imet_dict['pressure']))
    for i in range(0, n_frame, 20):
        res_string +=  "%d %d %d %s %s %d %d %d " % (imet_dict['pressure'][i], imet_dict['temperature'][i], imet_dict['humidity'][i], imet_dict['date'][i], imet_dict['time'][i], imet_dict['latitude'][i], imet_dict['longitude'][i], imet_dict['altitude'][i])
except:
    res_string =  "%d %d %d %s %s %d %d %d " % (imet_dict['pressure'][0], imet_dict['temperature'][0], imet_dict['humidity'][0], imet_dict['date'][0], imet_dict['time'][0], imet_dict['latitude'][0], imet_dict['longitude'][0], imet_dict['altitude'][0])

res_string += "%s %d" % (system_time, sys_min_alive)
#print(len(res_string))
print(res_string)