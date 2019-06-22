import psycopg2
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

#closing database connection.
if(connection):
    cursor.close()
    connection.close()
    #print("PostgreSQL connection is closed")


try:
    res_str = "%s %d %.3f %.3f %.3f %.3f %.3f" % (system_time, gps_time, gps_latitude, gps_longitude, gps_height, gps_velocity_x, gps_velocity_y)
    print(res_str)
except:
    #print("Error formatting data")
    pass