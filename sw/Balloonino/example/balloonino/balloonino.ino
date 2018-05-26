#include "pines_balloon.h"
#include "radio.h"
#include "imu.h"
#include "atms.h"
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

bool ballon_led_status = 0;

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
    pinMode(BALLOON_LED, OUTPUT);
}

void loop() {
    atms.updateData();
    imu.updateData();
    gps.updateData();
    rpy.getData();

    uint8_t base_cmd = radio.read_command();
    if (rpy.cmd_.port == CMD_RPY2RPY)
    {
        rpy.updateBeacon(&atms.atmsData, &gps.gpsData, &imu.gyroRate);
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
        digitalWrite(BALLOON_LED, ballon_led_status);
        ballon_led_status=!ballon_led_status;
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
        Serial.println(F("sending msg help"));
        rpy.send_msg("help");
    }
    else if (base_cmd == RESET_RPY)
    {
        Serial.println(F("sending msg reset"));
        rpy.send_msg("reset");
    }
    else if (base_cmd == RESET_MISSION_RPY)
    {
        Serial.println(F("sending msg reset_mission"));
        rpy.send_msg("reset_mission");
    }
    else if (base_cmd == REBOOT_RPY)
    {
        Serial.println(F("sending msg reboot"));
        rpy.send_msg("reboot");
    }
    else if (base_cmd == SEND_IRIDIUM)
    {
        Serial.println(F("sending msg send_iridium"));
        rpy.send_msg("send_iridium 1");
    }
    else if (base_cmd == GET_WEATHER)
    {
        Serial.println(F("sending msg send_weather_data"));
        rpy.send_msg("send_weather_data");
    }
    else if (base_cmd == CUT_BALLOON)
    {
        Serial.println(F("sending msg cut_balloon"));
        rpy.send_msg("cut_balloon 13");
    }
    else if (base_cmd == BALLOON_GET_DATA)
    {
        Serial.println(F("request data"));
        radio.send_data(dataD, dataF, dataU8, dataU32);
    }
    else{

    }
    base_cmd = 0;
}

// Debug Prints: TO DO
// Serial.print("gps.GPS_HH:");Serial.println(gps.hour);
// Serial.print("gps.GPS_MM:");Serial.println(gps.minute);
// Serial.print("gps.GPS_SS:");Serial.println(gps.second);
// Serial.print("gps.GPS_VAL:");Serial.println(gps.validity);
// Serial.print("gps.GPS_SAT:");Serial.println(gps.sat);