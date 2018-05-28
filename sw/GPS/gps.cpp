/**
 * @brief Simple GPS Library
 */
 
/*Author: Matias Vidal*/

#include "gps.h"

#define DEBUG_LEVEL 1

GPS::GPS(void) {
    gps_baudrate_ = 9600;
    serial_port_ = &Serial;
}

GPS::GPS(HardwareSerial *serial_port, int baudrate) {
    serial_port_ = serial_port;
    gps_baudrate_ = baudrate;
}

void GPS::init() {
    serial_port_->begin(gps_baudrate_);
}

void GPS::updateData() {
    while (serial_port_->available() > 0) {
        if (gps.encode(serial_port_->read())) {
            checkValidity();
            
            gpsData.latitude = gps.location.lat();
            gpsData.longitude = gps.location.lng();
            gpsData.altitude = gps.altitude.meters();
            gpsData.crse = gps.course.deg();
            gpsData.mps = gps.speed.mps();
            gpsData.hour = gps.time.hour();
            gpsData.minute = gps.time.minute();
            gpsData.second = gps.time.second();
            gpsData.satellites = gps.satellites.value();
        }
    }
    if (millis() > 5000 && gps.charsProcessed() < 10) {
        Serial.println(F("No GPS detected: check wiring."));
    }
}

void GPS::checkValidity(void) {
    uint8_t validity_ = 0;
    validity_ = gps.location.isValid()*(B1000000);
    validity_ += gps.altitude.isValid()*(B0100000);
    validity_ += gps.course.isValid()*(B00100000);
    validity_ += gps.speed.isValid()*(B00010000);
    validity_ += gps.time.isValid()*(B00001000);
    validity_ += gps.satellites.isValid()*(B00000100);
    gpsData.validity = validity_;
}