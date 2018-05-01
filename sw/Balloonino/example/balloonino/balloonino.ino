#include "radio.h"
#include "imu.h"
#include "atms.h"
#include "pines_balloon.h"
#include "gps.h"
#include "rpycom.h"
#include "dpl.h"

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
#define CMD_DEPLOY1 12
#define CMD_DEPLOY2 13

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
DPL dpl;

void setup()
{
    dpl.init();
    Serial.begin(115200);
    Serial1.begin(115200);
    // initialize
    radio.init();
    atms.init();
    imu.init();
    gps.init();
}

void loop() {
    // unsigned long time = millis();
    atms.updateData();
    imu.updateData();
    gps.updateData();
    updateAlldata();
    rpy.getData();
    // Serial.print("gps.GPS_HH:");Serial.println(gps.hour);
    // Serial.print("gps.GPS_MM:");Serial.println(gps.minute);
    // Serial.print("gps.GPS_SS:");Serial.println(gps.second);
    // Serial.print("gps.GPS_VAL:");Serial.println(gps.validity);
    // Serial.print("gps.GPS_SAT:");Serial.println(gps.sat);
    uint8_t base_cmd = radio.read_command();
    if (rpy.cmd_.port == CMD_RPY2RPY)
    {
        rpy.updateBeacon(dataD, dataF, dataU8, dataU32);
        rpy.sendData();
        rpy.resetStrutures();
    }
    else if (rpy.cmd_.port == CMD_RPY2BASE_DATA || rpy.cmd_.port == CMD_RPY2BASE_PHOTO)
    {
        Serial.println("sendingtoradio");
        radio.sendFrame(rpy.frame_rpy2base_, PACKET_SZ);
        for (int i = 0; i < PACKET_SZ-1; i++)
        {
            Serial.print(rpy.frame_rpy2base_[i]);Serial.print(",");
        }
        Serial.println("end");
    }
    else if (rpy.cmd_.port == CMD_DEPLOY1)
    {
        Serial.println(F("Demostración despliegue 1"));
        dpl.dem1();
    }
    else if (rpy.cmd_.port == CMD_DEPLOY2)
    {
        Serial.println(F("Demostración despliegue 2"));
        dpl.dem2();
    }
    if (base_cmd == HELP)
    {
        Serial.println(F("sending msg base2rpy"));
        rpy.send_msg("help");
    }
    else if (base_cmd == RESET_MISSION_RPY)
    {
        Serial.println(F("sending msg base2rpy"));
        rpy.send_msg("reset_mission");
    }
    else if (base_cmd == REBOOT_RPY)
    {
        Serial.println(F("sending msg base2rpy"));
        rpy.send_msg("reboot");
    }
}

void updateAlldata()
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
}