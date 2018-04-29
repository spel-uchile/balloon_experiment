#include "radio.h"
#include "imu.h"
#include "atms.h"
#include "pines_balloon.h"
#include "gps.h"
#include "rpycom.h"

/*Radio transiver*/
#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

/*GPS baudrate*/
#define GPS_BAUDRATE 9600

/*Rpy commands*/
#define RPY_GET_DATA 10
#define RPY_SEND_DATA 11

double dataD[8];
float dataF[6];
uint8_t dataU8[4];
uint32_t dataU32;

//Create an instance of the objects
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, RADIO_SDN, CLIENT_ADDRESS, SERVER_ADDRESS);
ATMS atms;
IMU imu(IMU_INTERRUPT, &Serial);
GPS gps;
RPYCOM rpy(&Serial1);

void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);
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
    dataF[2] = atms.temperature_dallas;
    dataF[3] = imu.gyroRate.x;
    dataF[4] = imu.gyroRate.y;
    dataF[5] = imu.gyroRate.z;
    dataU8[0] = gps.hour;
    dataU8[1] = gps.minute;
    dataU8[2] = gps.second;
    dataU8[3] = gps.validity;
    dataU32 = gps.sat;
    radio.send_data(dataD, dataF, dataU8);
    // rpy.BeacomTest();
    rpy.updateBeacom(dataD, dataF, dataU8, dataU32);
    // rpy.sendData();
    rpy.getData();
    Serial.print("node");Serial.println(rpy.cmd_.node);
    Serial.print("port");Serial.println(rpy.cmd_.port);
    if (rpy.cmd_.port == RPY_GET_DATA)
    {
        rpy.sendData();
    }
    else if (rpy.cmd_.port == RPY_SEND_DATA)
    {
        radio.send_data(dataD, dataF, dataU8);
    }
}
