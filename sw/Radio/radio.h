/**
 * @brief Simple Radio Library
 */

/*Author: Gustavo Diaz*/

/*Requiered Libraries*/
#include <Arduino.h>
#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>
#include "logger.h"
#include "atms_data.h"
#include "gps_data.h"
#include "helper_3dmath.h"

#define GET_PICTURE 1
#define GET_BEACON 2
#define RELEASE_BALLOON 3
#define PING 4
#define RESET_RPY 5
#define RESET_MISSION_RPY 6
#define REBOOT_RPY 7
#define HELP 8
#define SEND_IRIDIUM 9
#define GET_WEATHER 10
#define CUT_BALLOON 11
#define BALLOON_GET_DATA 13

/**
 * @class Radio
 * @brief Class for manage Radio data
 */

typedef struct {
    float Temp1;
    float Pressure;
    float Alt;
    float Temp2;
    float Humidity;
    float Temp3;
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
} frame_t;

class Radio
{
    /*Private Members*/
    frame_t beacon;
    frame_t beacon_tx_;

    uint8_t beacon_tx_size_ = sizeof(beacon_tx_);

    // Radio Object
    RH_RF22 driver;

    // Class to manage message delivery and receipt, using the driver declared above.
    RHReliableDatagram rf22;

    // Shutdown pin
    uint8_t sdn_pin_;

    // addr
    uint8_t addr_;
    uint8_t addr2_;

    // Debug
    // HardwareSerial *debug_port_;

public:
    /*Public Members*/

    // constructror parametrizado
    Radio(uint8_t radio_slaveselectpin, uint8_t radio_interrupt, uint8_t sdn, uint8_t addr, uint8_t addr2):
        driver(radio_slaveselectpin, radio_interrupt),
        addr_(addr),
        addr2_(addr2),
        rf22(driver, addr),
        sdn_pin_(sdn)
        // debug_port_(debug_port)
    {
        // Config pins
        pinMode(sdn_pin_, OUTPUT);
    }

    // methods
    void init(void);
    void sendFrame(uint8_t frame[], int frame_size);
    void sendData();
    void readData(void);
    void updateBeacon(AtmsData *atmsData, GpsData *gpsData, VectorInt16 *gyroData);
    bool sendCommand(uint8_t cmd);
    uint8_t readCommand(uint8_t *cmd);
    void infoPrint(void);

// private:
    // methods
    
};
