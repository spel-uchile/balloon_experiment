/**
 * @brief Simple Earth Station Example
 */
 
/*Author: Matías Vidal*/

#include "radio.h"

/*Radio transiver*/
#define RADIO_SLAVESELECTPIN 2
#define RADIO_INTERRUPT 3
#define SDN 4

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

/*Data store*/
double dataD[8];
float dataF[6];
uint8_t dataU8[4];
uint32_t dataU32;
char station_cmd;

/*Object Definitions*/
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, SDN, SERVER_ADDRESS, CLIENT_ADDRESS);

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    // initialize serial communication
    Serial.begin(115200);
    // init radio
    radio.init();
    displayCommands();
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    //radio.read_data(dataD, dataF, dataU8, dataU32);
    radio.read_frame();
    if (Serial.available() > 0) {
        station_cmd = Serial.read();
        if (station_cmd == '1') {
            Serial.println("Sending command Get Picture");
            radio.send_command(GET_PICTURE);
        }
        else if (station_cmd == '2') {
            Serial.println("Sending command Get Beacon");
            radio.send_command(GET_BEACON);
        }
        else if (station_cmd == '3') {
            Serial.println("Sending command Release Balloon");
            radio.send_command(RELEASE_BALLOON);
        }
        else if (station_cmd == '4') {
            Serial.println("Sending command Ping");
            radio.send_command(PING);
        }
        else if (station_cmd == '5') {
            Serial.println("Sending command reset Raspberry Pi");
            radio.send_command(RESET_RPY);
        }
        else if (station_cmd == '6') {
            Serial.println("Sending command Reset Mission Raspberry Pi");
            radio.send_command(RESET_MISSION_RPY);
        }
        else if (station_cmd == '7') {
            Serial.println("Sending command Reboot Raspberry Pi");
            radio.send_command(REBOOT_RPY);
        }
        else if (station_cmd == '8') {
            Serial.println("Sending command Help");
            radio.send_command(HELP);
        }
        else if (station_cmd == '9') {
            Serial.println("Sending command Send Iridium");
            radio.send_command(SEND_IRIDIUM);
        }
        else if (station_cmd == 'w') {
            Serial.println("Sending command Get Weather");
            radio.send_command(GET_WEATHER);
        }
        else if (station_cmd == 'c') {
            Serial.println("Sending command Cut Balloon");
            radio.send_command(CUT_BALLOON);
        }
        else if (station_cmd == 'd') {
            Serial.println("Sending command Balloon Get Data");
            radio.send_command(BALLOON_GET_DATA);
            radio.read_data(dataD, dataF, dataU8, dataU32);
        }
        else if (station_cmd == 'm') {
            displayCommands();
        }
        else
            Serial.println("Invalid command");
    }
}

void displayCommands() {
    Serial.println("GET_PICTURE       1");
    Serial.println("GET_BEACON        2");
    Serial.println("RELEASE_BALLOON   3");
    Serial.println("PING              4");
    Serial.println("RESET_RPY         5");
    Serial.println("RESET_MISSION_RPY 6");
    Serial.println("REBOOT_RPY        7");
    Serial.println("HELP              8");
    Serial.println("SEND_IRIDIUM      9");
    Serial.println("GET_WEATHER       w");
    Serial.println("CUT_BALLOON       c");
    Serial.println("BALLOON_GET_DATA  d");
    Serial.println("Display Commands  m");
}

