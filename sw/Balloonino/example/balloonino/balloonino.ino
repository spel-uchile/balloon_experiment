#include "radio.h"
#include "imu.h"
#include "atms.h"
#include "pines_balloon.h"
#include "gps.h"

/*Radio transiver*/
#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

/*GPS baudrate*/
#define GPS_BAUDRATE 9600

double dataD[8];
float dataF[5];
uint8_t dataU[4];

//Create an instance of the objects
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, RADIO_SDN, CLIENT_ADDRESS, SERVER_ADDRESS);
ATMS atms;
IMU imu(IMU_INTERRUPT, &Serial);
GPS gps;

void setup()
{
    // Wire.begin();        // Join i2c bus  
    Serial.begin(115200);
    // initialize
    radio.init();
    atms.init();
    imu.init();
    gps.init();
}

void loop() {
    atms.updateData();
    imu.updateData();
    gps.updateData();
    dataD[0] = atms.T;
    dataD[1] = atms.P;
    dataD[2] = atms.a;
    dataD[3] = gps.lat;
    dataD[4] = gps.lng;
    dataD[5] = gps.alt;
    dataD[6] = gps.crse;
    dataD[7] = gps.mps;
    dataF[0] = atms.tempC;
    dataF[1] = atms.humidity;
    dataF[2] = imu.ypr[0]*57.29;
    dataF[3] = imu.ypr[1]*57.29;
    dataF[4] = imu.ypr[2]*57.29;
    dataU[0] = gps.hour;
    dataU[1] = gps.minute;
    dataU[2] = gps.second;
    dataU[3] = gps.sat;
    radio.send_data(dataD, dataF, dataU);
}
