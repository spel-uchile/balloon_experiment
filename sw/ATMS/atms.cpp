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
    status_ = pressure_.getTemperature(T);
    status_ = pressure_.startPressure(3);
    delay(status_);
    status_ = pressure_.getPressure(P, T);
    a = pressure_.altitude(P, P0);
    delay(400);
    humidity = sensor_.getRH();
    tempC = sensor_.getTemp();
}