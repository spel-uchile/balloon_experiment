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

#define GET_PICTURE 1
#define GET_BEACON 2
#define RELEASE_BALLOON 3

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

    // addr
    uint8_t addr_;
    uint8_t addr2_;
    

    // Debug
    // HardwareSerial *debug_port_;

public:
    /*Public Members*/

    /*constructor de base (null)*/
    // Radio() {}

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
    void send_data(double dataD[], float dataF[], uint8_t dataU8[], uint32_t dataU32);
    void read_data(double dataD[], float dataF[], uint8_t dataU8[], uint32_t dataU32);
    bool send_command(uint8_t cmd);
    uint8_t read_command(void);
    void sendFrame(uint8_t frame[], int frame_size);

private:
    // methods
    void encode2byte(float number, uint8_t encode_bytes[]);
    void encode2byteD(double number, uint8_t encode_bytes[]);
    void encode3byte(double number, uint8_t encode_bytes[]);
    void encode4byteD(double number, uint8_t encode_bytes[]);
    void encode(double dataD[], float dataF[], uint8_t dataU8[], uint32_t dataU32, uint8_t frame[]);
    float decode2byte(uint8_t byte1, uint8_t byte2);
    double decode2byteD(uint8_t byte1, uint8_t byte2);
    double decode3byte(uint8_t byte1, uint8_t byte2, uint8_t byte3);
    double decode4byteD(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4);
    void decode(uint8_t frame[], double dataD[], float dataF[], uint8_t dataU8[], uint32_t dataU32);
    void displayData(double dataD[], float dataF[], uint8_t dataU8[], uint32_t dataU32);
};
