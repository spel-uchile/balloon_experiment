/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

#include "radio.h"

/*Radio transiver*/
#define RADIO_SLAVESELECTPIN 2
#define RADIO_INTERRUPT 3
#define SDN 4

/*Data store*/
double dataD[3];
float dataF[5];

/*Object Definitions*/
Radio radio(RADIO_SLAVESELECTPIN, RADIO_INTERRUPT, SDN);

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
    radio.read_data(dataD, dataF);
    displayData(dataD, dataF);
    
}

void displayData(double dataD[], float dataF[])
{
    DEBUG2_PRINT("Data:\t");
    for (int j = 0; j < sizeof(dataD); j++)
    {
        DEBUG2_PRINT(dataD[j]);DEBUG2_PRINT("\t");
    }
    for (int j = 0; j < sizeof(dataF); j++)
    {
        DEBUG2_PRINT(dataF[j]);DEBUG2_PRINT("\t");
    }
    DEBUG2_PRINTLN("\t");
}