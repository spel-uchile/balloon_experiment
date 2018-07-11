import sqlite3
conn = sqlite3.connect('/tmp/suchai.db')
c = conn.cursor()

for row in c.execute('SELECT * FROM gps_table ORDER BY idx DESC LIMIT 1'):
    print row
