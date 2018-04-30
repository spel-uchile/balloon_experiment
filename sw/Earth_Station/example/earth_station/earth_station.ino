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
}
