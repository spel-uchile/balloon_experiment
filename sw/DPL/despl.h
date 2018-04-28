/**
 * @brief Simple ATMS Library
 */

/*Author: Gustavo Diaz*/

/*Requiered Libraries*/
#include  <Servo.h>

#define DEBUG_LEVEL 1
/*Constants*/
#define  start_m1 0 // Inicio 
#define  start_m2 0 // Inicio 
#define  end_m1 180 // Inicio 
#define  end_m2 180 // Inicio 



/**
 * @class ATMS
 * @brief Class for manage Atmospheric sensors
 */

class DESPL
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

    /*constructor de base (null)*/
    DESPL() {}

    // methods
    void init(void);
    void Rdesp1_start(void);
    void Rdesp2_start(void);
    void Rdesp1_end(void);
    void Rdesp2_end(void);
    void Act_m1(void);
    void Act_m2(void);
    void dem1(void);
    void dem2(void);
    void restart(void);

// private:
    // methods
};
