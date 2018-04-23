#include <TinyGPS++.h>
#include "radio.h"
#include "imu.h"
#include "atms.h"
#include "pines_balloon.h"

/*Radio transiver*/
#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

static const uint32_t GPSBaud = 9600;
double dataD[3];
float dataF[5];

//Create an instance of the objects
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, RADIO_SDN, CLIENT_ADDRESS, SERVER_ADDRESS);
ATMS atms;
IMU imu(IMU_INTERRUPT, &Serial);
TinyGPSPlus gps;

void setup()
{
    // Wire.begin();        // Join i2c bus  
    Serial.begin(115200);
    // initialize
    Serial2.begin(GPSBaud);
    radio.init();
    atms.init();
    imu.init();
}

void loop() {
    while (Serial2.available() > 0) {
        if (gps.encode(Serial2.read())) {
            Serial.print("Latitude: ");
            Serial.print(gps.location.lat());
            Serial.print("    Longitude: ");
            Serial.print(gps.location.lng());
            Serial.print("      Altitude (m): ");
            Serial.print(gps.altitude.meters());
            Serial.print("      Course: ");
            Serial.print(gps.course.deg());
            Serial.print("      Speed (m/s): ");
            Serial.print(gps.speed.mps());
            Serial.print("      Time: ");
            Serial.print(gps.time.hour());
            Serial.print(":");
            Serial.print(gps.time.minute());
            Serial.print(":");
            Serial.print(gps.time.second());
            Serial.print("      Satellites: ");
            Serial.println(gps.satellites.value());
        }
    }
    
    atms.updateData();
    imu.updateData();
    dataD[0] = atms.T;
    dataD[1] = atms.P;
    dataD[2] = atms.a;
    dataF[0] = atms.tempC;
    dataF[1] = atms.humidity;
    dataF[2] = imu.ypr[0]*57.29;
    dataF[3] = imu.ypr[1]*57.29;
    dataF[4] = imu.ypr[2]*57.29;
    radio.send_data(dataD, dataF);
}
