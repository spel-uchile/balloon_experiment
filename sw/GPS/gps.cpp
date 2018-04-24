/**
 * @brief Simple GPS Library
 */
 
/*Author: Matias Vidal*/

#include "gps.h"

#define DEBUG_LEVEL 1

GPS::GPS() {
    gps_baudrate = 9600;
}

GPS::GPS(int baudrate) {
    gps_baudrate = baudrate;
}

void GPS::init() {
    Serial2.begin(gps_baudrate);
}

void GPS::updateData() {
    lat = gps.location.lat();
    lng = gps.location.lng();
    alt = gps.altitude.meters();
    crse = gps.course.deg();
    mps = gps.speed.mps();
    hour = gps.time.hour();
    minute = gps.time.minute();
    second = gps.time.second();
    sat = gps.satellites.value();
}

