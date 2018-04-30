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
#define CMD_RPY2RPY 10
#define CMD_BASE2RPY 11
#define CMD_RPY2BASE_DATA 20
#define CMD_RPY2BASE_PHOTO 21

double dataD[8];
float dataF[6];
uint8_t dataU8[4];
uint32_t dataU32;

uint8_t frame_rpy2base[PACKET_SZ];

//Create an instance of the objects
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, RADIO_SDN, CLIENT_ADDRESS, SERVER_ADDRESS);
ATMS atms(PIN_DALLAS);
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
    // memset(frame_rpy2base, 0, PACKET_SZ);
    // rpy.getData(frame_rpy2base);
    rpy.getData();
    // uint8_t base_cmd = radio.read_command();
    if (rpy.cmd_.port == CMD_RPY2RPY)
    {
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

        rpy.updateBeacon(dataD, dataF, dataU8, dataU32);
        rpy.sendData();
        rpy.resetStrutures();
    }
    else if (rpy.cmd_.port == CMD_RPY2BASE_DATA || rpy.cmd_.port == CMD_RPY2BASE_PHOTO)
    {
        // radio.send_data(dataD, dataF, dataU8);
        radio.sendFrame(frame_rpy2base, PACKET_SZ);
    }
    else
    {
        // to do
        radio.send_data(dataD, dataF, dataU8, dataU32);
    }
    // if (base_cmd == GET_BEACON)
    // {
    //     rpy.updateBeacom(dataD, dataF, dataU8, dataU32);
    //     rpy.sendData();
    // }
}
