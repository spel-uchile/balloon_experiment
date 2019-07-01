#!/usr/bin/python3
import os.path
import glob
import datetime

def get_latest_file():
    list_of_files = glob.glob('/home/pi/test_pictures/*.txt')
    print(list_of_files)
    if len(list_of_files) > 0:
        return os.path.split(max(list_of_files,key=os.path.getctime))[1]

if __name__ == '__main__':
    last_file = get_latest_file()files
    print(files)