/**
 * @brief Simple IMU Example
 */
 
/*Author: Gustavo Diaz*/

/*Requiered Libraries*/
#include "atms.h"

/*Debug print levels*/
#define LOGGER_MIN_SEVERITY LOGGER_SEVERITY_INFO

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
    INFO_PRINTLN_RAW("temp1\tpressure\taltitude\ttemp2\thumidity\ttemperatureDallas");
    INFO_PRINT_RAW(atms.atmsData.temperature1);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(atms.atmsData.pressure);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(atms.atmsData.altitude);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(atms.atmsData.temperature2);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(atms.atmsData.humidity);INFO_PRINT_RAW("\t");
    INFO_PRINTLN_RAW(atms.atmsData.temperatureDallas);
}
