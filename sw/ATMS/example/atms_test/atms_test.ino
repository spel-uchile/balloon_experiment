/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

#include "atms.h"

#define PIN_DALLAS 42
/*Object Definitions*/
ATMS atms(PIN_DALLAS);

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    // initialize serial communication
    Serial.begin(115200);
    // init atms
    atms.init();
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop()
{
    atms.updateData();
    DEBUG2_PRINT("T-P-a-tempC-humidity:\t");
    DEBUG2_PRINT(atms.T);DEBUG2_PRINT("\t");
    DEBUG2_PRINT(atms.P);DEBUG2_PRINT("\t");
    DEBUG2_PRINT(atms.a);DEBUG2_PRINT("\t");
    DEBUG2_PRINT(atms.tempC);DEBUG2_PRINT("\t");
    DEBUG2_PRINTLN(atms.humidity)
    DEBUG2_PRINTLN(atms.temperature_dallas)
}
