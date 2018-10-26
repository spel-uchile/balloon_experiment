#include "gps.h"

/*GPS baudrate*/
#define GPS_BAUDRATE 9600

/*Debug print levels*/
#define LOGGER_MIN_SEVERITY LOGGER_SEVERITY_NONE

/*Create an instance of the objects*/
/*  If Serial is used the logger should be disabled (i.e. LOGGER_SEVERITY_NONE)
    If othrt Hardware Serial is available is possible to use the logger with Serial
*/
GPS gps(&Serial, GPS_BAUDRATE);

void setup() {
    // initialize
    gps.init();
    delay(500);
}

void loop() {
    gps.updateData();
    INFO_PRINT_RAW("Latitude,Longitude: ");
    INFO_PRINT_RAW(gps.gpsData.latitude, 6);
    INFO_PRINT_RAW(",");
    INFO_PRINT_RAW(gps.gpsData.longitude, 6);
    INFO_PRINT_RAW("      Altitude (m): ");
    INFO_PRINT_RAW(gps.gpsData.altitude);
    INFO_PRINT_RAW("      Course: ");
    INFO_PRINT_RAW(gps.gpsData.crse);
    INFO_PRINT_RAW("      Speed (m/s): ");
    INFO_PRINT_RAW(gps.gpsData.mps);
    INFO_PRINT_RAW("      Time: ");
    INFO_PRINT_RAW(gps.gpsData.hour);
    INFO_PRINT_RAW(":");
    INFO_PRINT_RAW(gps.gpsData.minute);
    INFO_PRINT_RAW(":");
    INFO_PRINT_RAW(gps.gpsData.second);
    INFO_PRINT_RAW("      Satellites: ");
    INFO_PRINT_RAW(gps.gpsData.satellites);
    INFO_PRINT_RAW("      Validity: ");
    INFO_PRINTLN_RAW(gps.gpsData.validity, BIN);
    delay(500);
}
