/**
 * @brief Simple IMU Library
 */
 
/*Author: Gustavo Diaz*/

#include "atms.h"

//-------------------------- Public Methods --------------------------

void ATMS::init(void)
{
	pressure_.begin();
}

void ATMS::updateData(void)
{
    status_ = pressure_.startTemperature();
    delay(status_);
    status_ = pressure_.getTemperature(atmsData.temperature1);
    status_ = pressure_.startPressure(3);
    delay(status_);
    status_ = pressure_.getPressure(atmsData.pressure, atmsData.temperature1);
    atmsData.altitude = pressure_.altitude(atmsData.pressure, P0);
    delay(400);
    atmsData.humidity = sensor_.getRH();
    atmsData.temperature2 = sensor_.getTemp();
    sensorT_.requestTemperatures();
    atmsData.temperatureDallas = sensorT_.getTempCByIndex(0);
}

void ATMS::infoPrint(void)
{
    INFO_PRINTLN_RAW("temp1\tpressure\taltitude\ttemp2\thumidity\ttemperatureDallas");
    INFO_PRINT_RAW(atmsData.temperature1);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(atmsData.pressure);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(atmsData.altitude);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(atmsData.temperature2);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(atmsData.humidity);INFO_PRINT_RAW("\t");
    INFO_PRINTLN_RAW(atmsData.temperatureDallas);
}