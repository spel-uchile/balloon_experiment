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

/*Debug print levels*/
#define LOGGER_MIN_SEVERITY LOGGER_SEVERITY_NONE

uint8_t frame_rpy2base[PACKET_SZ];

bool ballon_led_status = 0;

//Create an instance of the objects
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, RADIO_SDN, CLIENT_ADDRESS, SERVER_ADDRESS);
ATMS atms(PIN_DALLAS);
IMU imu(IMU_INTERRUPT, &Serial);
GPS gps(&Serial, GPS_BAUDRATE);
// RPYCOM rpy(&Serial1);
DPL dpl;
uint8_t base_cmd;

void setup()
{
    dpl.init();
    // Serial.begin(115200);
    // Serial1.begin(115200);
    // initialize
    radio.init();
    atms.init();
    imu.init();
    gps.init();
    pinMode(BALLOON_LED, OUTPUT);
}

void loop() {
	/*Update sensor data*/
    atms.updateData();
    imu.updateData();
    gps.updateData();

    /*Update commands*/
    radio.readCommand(&base_cmd);

    if (base_cmd == HELP)
    {
        INFO_PRINTLN_RAW(F("sending msg help"));
        // rpy.send_msg("help");
    }
    else if (base_cmd == RESET_RPY)
    {
        INFO_PRINTLN_RAW(F("sending msg reset"));
        // rpy.send_msg("reset");
    }
    else if (base_cmd == RESET_MISSION_RPY)
    {
        INFO_PRINTLN_RAW(F("sending msg reset_mission"));
        // rpy.send_msg("reset_mission");
    }
    else if (base_cmd == REBOOT_RPY)
    {
        INFO_PRINTLN_RAW(F("sending msg reboot"));
        // rpy.send_msg("reboot");
    }
    else if (base_cmd == SEND_IRIDIUM)
    {
        INFO_PRINTLN_RAW(F("sending msg send_iridium"));
        // rpy.send_msg("send_iridium 1");
    }
    else if (base_cmd == GET_WEATHER)
    {
        INFO_PRINTLN_RAW(F("sending msg send_weather_data"));
        // rpy.send_msg("send_weather_data");
    }
    else if (base_cmd == CUT_BALLOON)
    {
        INFO_PRINTLN_RAW(F("sending msg cut_balloon"));
        // rpy.send_msg("cut_balloon 13");
    }
    else if (base_cmd == BALLOON_GET_DATA)
    {
        INFO_PRINTLN_RAW(F("request data"));
        radio.updateBeacon(&atms.atmsData, &gps.gpsData, &imu.gyroRate);
        radio.sendData();
    }
    else{
    	INFO_PRINTLN_RAW(F("Unknown command"));
    }
    base_cmd = 0;
}