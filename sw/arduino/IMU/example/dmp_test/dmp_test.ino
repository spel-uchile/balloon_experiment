/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

#include "imu.h"


/*Pin definitions*/
#define INTERRUPT_PIN 31

/*Object Definitions*/
IMU imu(INTERRUPT_PIN, &Serial);

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    // initialize serial communication
    Serial.begin(115200);
    // initialize IMU
    imu.init();
}



// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop()
{
    imu.updateData();
    DEBUG2_PRINT("ypr:\t");
    DEBUG2_PRINT(imu.ypr[0]*57.29);DEBUG2_PRINT("\t");
    DEBUG2_PRINT(imu.ypr[1]*57.29);DEBUG2_PRINT("\t");
    DEBUG2_PRINTLN(imu.ypr[2]*57.29);
    // delay(1000); //for testing worst case
}