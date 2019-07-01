import psycopg2
import time
#from gpiozero import *
#ch_select1 = LED(4)
#ch_select2 = LED(17)
#ch_select1.off()
#ch_select2.off()
#time.sleep(5)
try:
    connection = psycopg2.connect(user = "pi", password = "pi", database = "fs_db")
    cursor = connection.cursor()
except (Exception, psycopg2.Error) as error :
    #print ("Error while connecting to PostgreSQL", error)
    pass

#get gps data
try:
    cursor.execute('SELECT * FROM gps_data ORDER BY tstz DESC LIMIT 1')
    row_gps = cursor.fetchone()
    system_time = row_gps[0]
    gps_time = row_gps[1]
    gps_latitude = row_gps[2]
    gps_longitude = row_gps[3]
    gps_height = row_gps[4]
    gps_velocity_x = row_gps[5]
    gps_velocity_y = row_gps[6]
    gps_satellites = row_gps[7]
    gps_mode = row_gps[8]
except:
    #print ("Error reading gps data")
    pass

#get dpl data
try:
    cursor.execute('SELECT * FROM dpl_data ORDER BY tstz DESC LIMIT 1')
    row_dpl = cursor.fetchone()
    dpl_port_status = row_dpl[2]

except:
    #print ("Error reading dpl data")
    pass

#get prs data
try:
    cursor.execute('SELECT * FROM prs_data ORDER BY tstz DESC LIMIT 1')
    row_prs = cursor.fetchone()
    prs_pressure = row_prs[2]
    prs_temperature = row_prs[3]
    prs_height = row_prs[4]
except:
    #print ("Error reading dpl data")
    pass

#closing database connection.
if(connection):
    cursor.close()
    connection.close()
    #print("PostgreSQL connection is closed")


try:
    #Select 144.930 MHz (argentina)
    #ch_select1.off()
    #ch_select2.off()
    res_str = "%s %d %.3f %.3f %.3f %.3f %.3f %d %.3f %.3f %.3f" % (system_time, gps_time, gps_latitude, gps_longitude, gps_height, gps_velocity_x, gps_velocity_y, dpl_port_status, prs_pressure, prs_temperature, prs_height)
    print(res_str)
except:
    #print("Error formatting data")
    pass