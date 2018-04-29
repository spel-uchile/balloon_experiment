/**
 * @brief Simple Raspberry Pi communication Library
 */

/*Author: Matías Vidal*/

/*Requiered Libraries*/
#include <Arduino.h>
#define PACKET_SZ 64
#define CMD_SZ 2
#define STRUCT_SZ 60
#define DATA_SZ PACKET_SZ - CMD_SZ - STRUCT_SZ

/**
 * @class OBC
 * @brief Class for manage commands between Raspberry Pi 3 and Arduino Due
 */
 
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
    uint8_t GPS_validity;
    uint32_t GPS_Sat;
} frame;

typedef struct {
    uint8_t node;
    uint8_t port;
} command;

class RPYCOM
{
    /*Private Members*/
    uint8_t node_ = 1;
    uint8_t port_ = 10;
    frame beacon_tx_;
    frame beacon_rx_;
    uint8_t beacon_tx_size_ = sizeof(beacon_tx_);
    uint8_t data_[DATA_SZ];

    HardwareSerial *hw_port_;

    public:
        /*Public Members*/
        command cmd_;

        /*constructor de base (null)*/
        RPYCOM(HardwareSerial *hw_port):
        hw_port_(hw_port)
        {
            cmd_.port = 0;
        }

        /*Methods*/
        void updateBeacom(double dataD[], float dataF[], uint8_t dataU8[], uint32_t dataU32);
        void BeacomTest();
        void getData();
        void sendData();
        void resetStrutures();
    // private:
        // methods
};