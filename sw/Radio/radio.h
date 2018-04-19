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

/*Constants*/
#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

/**
 * @class Radio
 * @brief Class for manage Radio data
 */

class Radio
{
    /*Private Members*/

    // Radio Object
    RH_RF22 driver;

    // Class to manage message delivery and receipt, using the driver declared above.
    RHReliableDatagram rf22;

    // Shutdown pin
    uint8_t sdn_pin_;

    // Debug
    // HardwareSerial *debug_port_;

public:
    /*Public Members*/

    /*constructor de base (null)*/
    // Radio() {}

    // constructror parametrizado
    Radio(uint8_t radio_slaveselectpin, uint8_t radio_interrupt, uint8_t sdn):
        driver(radio_slaveselectpin, radio_interrupt),
        rf22(driver, CLIENT_ADDRESS),
        sdn_pin_(sdn)
        // debug_port_(debug_port)
    {
        // Config pins
        pinMode(sdn_pin_, OUTPUT);
    }

    // methods
    void init(void);
    void send_data(double dataD[], float dataF[]);
    void read_data(double dataD[], float dataF[]);

private:
    // methods
    void sendFrame(uint8_t frame[], int frame_size);
    void encode2byte(float number, uint8_t encode_bytes[]);
    void encode2byteD(double number, uint8_t encode_bytes[]);
    void encode3byte(double number, uint8_t encode_bytes[]);
    void encode(double dataD[], float dataF[], uint8_t frame[]);
    float decode2byte(uint8_t byte1, uint8_t byte2);
    double decode2byteD(uint8_t byte1, uint8_t byte2);
    double decode3byte(uint8_t byte1, uint8_t byte2, uint8_t byte3);
    void decode(uint8_t frame[], double dataD[], float dataF[]);
};