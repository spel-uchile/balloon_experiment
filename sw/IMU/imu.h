/**
   @brief Simple ATMS Library
*/

/*Author: Gustavo Diaz*/

/*Requiered Libraries*/
#include <Arduino.h>
#include <SparkFunMPU9250-DMP.h>
#include "imu_data.h"
#include "logger.h"

/**
   @class IMU
   @brief Class for manage IMU
*/

class IMU9250
{
    /*Private Members*/
    MPU9250_DMP imu_;

  public:
    /*Public Members*/
    ImuData imuData;

    /*constructor de base (null)*/
    IMU9250() {}

    // methods
    void init(void);
    void updateData(void);
    void infoPrint(void);

    // private:
    // ...methods
};
