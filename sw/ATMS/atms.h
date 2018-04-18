/**
 * @brief Simple ATMS Library
 */

/*Author: Gustavo Diaz*/

/*Requiered Libraries*/
#include <Arduino.h>
#include <Wire.h>
#include <SFE_BMP180.h>
#include "SparkFun_Si7021_Breakout_Library.h"
#include "logger.h"

/*Constants*/
#define P0 1013.25

/**
 * @class ATMS
 * @brief Class for manage Atmospheric sensors
 */

class ATMS
{
    /*Private Members*/

    // ATMS Objects
    SFE_BMP180 pressure_;
    Weather sensor_;

    // Internal Variables
    char status_;

    // Debug
    // HardwareSerial *debug_port_;

public:
    /*Public Members*/
    double T, P, a;
    float tempC, humidity;

    /*constructor de base (null)*/
    ATMS() {}

    // methods
    void init(void);
    void updateData(void);

// private:
    // methods
};