/**
 * @brief Simple ATMS Library
 */

/*Author: Gustavo Diaz*/

/*Requiered Libraries*/
#include <Arduino.h>
#include  <Servo.h>
#include "pines_balloon.h"

/*Constants*/
#define  start_s1 0 // Begin 
#define  start_s2 180 // Begin
#define  end_s1 180 // Begin 
#define  end_s2 0 // Begin



/**
 * @class ATMS
 * @brief Class for manage Atmospheric sensors
 */

class DPL
{
    /*Private Members*/

    // DLP Objects
    Servo myservo1_;
    Servo myservo2_;
    //SFE_BMP180 pressure_;
    //Weather sensor_;

    // Internal Variables
    //char status_;

    // Debug
    // HardwareSerial *debug_port_;

public:
    /*Public Members*/
    //double T, P, a;
    //float tempC, humidity;

    /*Base contructor (null)*/
    DPL() {}

    // methods
    void init(void);
    void Rdpl1_start(void);
    void Rdpl2_start(void);
    void Rdpl1_end(void);
    void Rdpl2_end(void);
    void Act_s1(void);
    void Act_s2(void);
    void dem1(void);
    void dem2(void);
    void restart(void);

// private:
    // methods
};
