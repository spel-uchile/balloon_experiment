/**
   @brief Simple ATMS Library
*/

/*Author: Gustavo Diaz*/

/*Requiered Libraries*/
#include <Arduino.h>
#include <Wire.h>
#include <SFE_BMP180.h>
#include "SparkFun_Si7021_Breakout_Library.h"
#include "logger.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "atms_data.h"

/*Constants*/
#define P0 1013.25
/**
   @class ATMS
   @brief Class for manage Atmospheric sensors
*/

class ATMS
{
    /*Private Members*/

    // ATMS Objects
    SFE_BMP180 pressure_;
    Weather sensor_;
    DallasTemperature sensorT_;

    OneWire oneWireBus_;

    // Internal Variables
    char status_;

  public:
    /*Public Members*/
    AtmsData atmsData;

    /*constructor de base (null)*/
    ATMS(uint8_t oneWirePin):
      oneWireBus_(oneWirePin),
      sensorT_(&oneWireBus_)
    {}

    // methods
    void init(void);
    void updateData(void);

    // private:
    // ...methods
};
