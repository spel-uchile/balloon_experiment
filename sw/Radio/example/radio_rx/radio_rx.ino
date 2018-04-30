/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

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

void loop()
{
    radio.read_data(dataD, dataF, dataU8, dataU32);
    radio.displayData(dataD, dataF, dataU8, dataU32);
}
/*
void displayData(double dataD[], float dataF[])
{
    DEBUG2_PRINT("Data:\t");
    for (int j = 0; j < 3; j++)
    {
        DEBUG2_PRINT(dataD[j]);DEBUG2_PRINT("\t");
    }
    for (int j = 0; j < 5; j++)
    {
        DEBUG2_PRINT(dataF[j]);DEBUG2_PRINT("\t");
    }
    DEBUG2_PRINTLN("\t");
}
*/
