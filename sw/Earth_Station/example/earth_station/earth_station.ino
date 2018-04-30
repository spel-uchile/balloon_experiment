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
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    //radio.read_data(dataD, dataF, dataU8, dataU32);
    radio.read_frame();
    if (Serial.available() > 0) {
        station_cmd = Serial.read();
        if (station_cmd == 'p') {
            Serial.println("Sending command get picture");
            radio.send_command(GET_PICTURE);
        }
        else if (station_cmd == 'b') {
            Serial.println("Sending command get beacon");
            radio.send_command(GET_BEACON);
        }
        else if (station_cmd == 'r') {
            Serial.println("Sending command release balloon");
            radio.send_command(RELEASE_BALLOON);
        }
        else
            Serial.println("Invalid command");
    }
}
