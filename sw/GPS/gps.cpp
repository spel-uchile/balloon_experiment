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
            if (gps.location.isValid()) {
                lat = gps.location.lat();
                lng = gps.location.lng();
            }
            else
                Serial.print("Invalid location data");
            if (gps.altitude.isValid()) {
                alt = gps.altitude.meters();
            }
            else
                Serial.print("    Invalid altitude data");
            if (gps.course.isValid()) {
                crse = gps.course.deg();
            }
            else
                Serial.print("    Invalid course data");
            if (gps.speed.isValid()) {
                mps = gps.speed.mps();
            }
            else
                Serial.print("    Invalid speed data");
            if (gps.time.isValid()) {
                hour = gps.time.hour();
                minute = gps.time.minute();
                second = gps.time.second();
            }
            else
                Serial.print("    Invalid time data");
            if (gps.satellites.isValid()) {
                sat = gps.satellites.value();
            }
            else
                Serial.println("    Invalid satellites data");
        }
    }
    if (millis() > 5000 && gps.charsProcessed() < 10) {
        Serial.println(F("No GPS detected: check wiring."));
    }
}

