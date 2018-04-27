/**
 * @brief Simple GPS Library
 */
 
/*Author: Matias Vidal*/

#include "gps.h"

#define DEBUG_LEVEL 1

GPS::GPS(void) {
    gps_baudrate = 9600;
}

GPS::GPS(int baudrate) {
    gps_baudrate = baudrate;
}

void GPS::init() {
    Serial2.begin(gps_baudrate);
}

void GPS::updateData() {
    while (Serial2.available() > 0) {
        if (gps.encode(Serial2.read())) {
            checkValidity();
            
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
    }
    if (millis() > 5000 && gps.charsProcessed() < 10) {
        Serial.println(F("No GPS detected: check wiring."));
    }
}

void GPS::checkValidity(void) {
    validity = 0;
    validity = gps.location.isValid()*(b1000000);
    validity += gps.altitude.isValid()*(b0100000);
    validity += gps.course.isValid()*(b00100000);
    validity += gps.speed.isValid()*(b00010000);
    validity += gps.time.isValid()*(b00001000);
    validity += gps.satellites.isValid()*(b00000100);
}

