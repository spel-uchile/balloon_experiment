/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

#include "radio.h"
#include "atms_data.h"
#include "gps_data.h"
#include "helper_3dmath.h"

/*Radio transiver*/
#define RADIO_SLAVESELECTPIN 4
#define RADIO_INTERRUPT 2
#define SDN 10

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

/*Debug print levels*/
#define LOGGER_MIN_SEVERITY LOGGER_SEVERITY_INFO

/*Test Data*/
AtmsData atmsData;
GpsData gpsData;
VectorInt16 gyroRate;

/*Object Definitions*/
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, SDN, CLIENT_ADDRESS, SERVER_ADDRESS);

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    // initialize serial communication
    Serial.begin(115200);
    // init radio
    radio.init();
    // Test Data
    testData();
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop()
{
    radio.updateBeacon(&atmsData, &gpsData, &gyroRate);
    radio.sendData();
}

void testData(void)
{
    atmsData.temperature1 = 12.5;
    atmsData.pressure = 78.6;
    atmsData.altitude = 187.7;
    atmsData.temperature2 = 13.9;
    atmsData.temperatureDallas = 27.2;
    atmsData.humidity = 3.45;

    gpsData.latitude = 25.1;
    gpsData.longitude = 32.7;
    gpsData.altitude = 25.1;
    gpsData.crse = 25.1;
    gpsData.mps = 25.1;
    gpsData.hour = 25.1;
    gpsData.minute = 25.1;
    gpsData.second = 25.1;
    gpsData.satellites = 25.1;
    gpsData.validity = 87;

    gyroRate.x = 35;
    gyroRate.y = 21;
    gyroRate.z = 12;
}