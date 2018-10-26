/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

#include "rpycom.h"

/*Object Definitions*/
RPYCOM rpy(&Serial1);

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    // initialize serial communication
    Serial1.begin(115200);
    Serial.begin(115200);
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop()
{
    // test data
    rpy.BeacomTest();
    rpy.sendData();
    delay(1000);
}
