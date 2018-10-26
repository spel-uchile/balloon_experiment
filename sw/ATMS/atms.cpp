/**
 * @brief Simple IMU Library
 */
 
/*Author: Gustavo Diaz*/

#include "atms.h"

#define DEBUG_LEVEL 1

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
