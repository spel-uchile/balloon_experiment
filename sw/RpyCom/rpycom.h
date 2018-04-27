/**
 * @brief Simple Raspberry Pi communication Library
 */

/*Author: Matías Vidal*/

/*Requiered Libraries*/
#include <Arduino.h>


/**
 * @class OBC
 * @brief Class for manage commands between Raspberry Pi 3 and Arduino Due
 */
 
 class OBC {
    typedef struct {
        float Temp1;
        float Pressure;
        float Alt;
        float Temp2;
        float Humidity;
        float IMU1;
        float IMU2;
        float IMU3;
        float GPS_Lat;
        float GPS_Lng;
        float GPS_Alt;
        float GPS_Crse;
        float GPS_Speed;
        uint8_t GPS_HH;
        uint8_t GPS_MM;
        uint8_t GPS_SS;
        uint32_t GPS_Sat;
    } frame;
    public:
        void init(void);
        void updateData(double dataD[], float dataF[], uint8_t dataU[]);
        void getData(void* frame);
        void sendData(void* frame);
    private:
    
 }
