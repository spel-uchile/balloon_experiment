/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

#include "radio.h"

/*Radio transiver*/
#define RADIO_SLAVESELECTPIN 4
#define RADIO_INTERRUPT 2
#define SDN 10

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

/*Data store*/
double dataD[3];
float dataF[5];
uint8_t dataU8[4];

/*Object Definitions*/
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, SDN, CLIENT_ADDRESS, SERVER_ADDRESS);

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

void loop()
{
    // test data
    dataD[0] = 123.45;
    dataD[1] = 956.76;
    dataD[2] = -75.01;
    dataF[0] = 98.3;
    dataF[1] = 21.7;
    dataF[2] = 87.80;
    dataF[3] = 101.71;
    dataF[4] = 43.87;
    dataU8[0] = 25;
    dataU8[1] = 8;
    dataU8[2] = 25;
    dataU8[3] = 87;
    // send data as predefined Frame
    radio.send_data(dataD, dataF, dataU8);
}
