#include "radio.h"
#include "imu.h"
#include "atms.h"
#include "pines_balloon.h"

/*Radio transiver*/
#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

double dataD[3];
float dataF[5];

//Create an instance of the objects
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, RADIO_SDN, CLIENT_ADDRESS, SERVER_ADDRESS);
ATMS atms;
IMU imu(IMU_INTERRUPT, &Serial);

void setup()
{
    // Wire.begin();        // Join i2c bus  
    Serial.begin(115200);
    // initialize
    radio.init();
    atms.init();
    imu.init();
}

void loop() {
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