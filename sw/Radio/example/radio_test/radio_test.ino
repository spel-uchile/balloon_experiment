/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

#include "radio.h"
#include "pines_radio.h"

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
    // test data
    dataD[0] = 123.45;
    dataD[1] = 956.76;
    dataD[2] = 75.01;
    dataF[0] = 98.3;
    dataF[1] = 21.7;
    dataF[2] = 87.80;
    dataF[3] = 101.71;
    dataF[4] = 43.87;
    // send data as predefined Frame
    radio.send_data(dataD, dataF);
}
