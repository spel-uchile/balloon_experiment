/**
 * @brief Simple IMU Library
 */
 
/*Author: Gustavo Diaz*/

#include "radio.h"

#define DEBUG_LEVEL 1

//-------------------------- Public Methods --------------------------

void Radio::init(void)
{
	digitalWrite(sdn_pin_, LOW);
	delay(1500);
   if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    Serial.println(F("Unidirectional test (TX)"));
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(437.225, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    if (!driver.setModemConfig(driver.FSK_Rb2Fd5)) {
        Serial.println(F("Configuration error"));    
    }
    rf22.setRetries(3);
    Serial.println(F("Set Tx Power = RH_RF22_TXPOW_20DB"));
    Serial.println(F("Set configuration = FSK_Rb2Fd5"));  
}

/**
 * This function sends a packet to the receiver and then it waits for a confirmation,
 * if there is no acknowledge, an error is printed on screen.
 * @param data[] Data sent to the receiver..
 * @param data_size Size of the packet to be sent.
 */
void Radio::sendFrame(uint8_t frame[], int frame_size)
{
    if (!rf22.sendtoWait(frame, frame_size, SERVER_ADDRESS))
        Serial.println(F("sendtoWait failed"));
}

/**
 * The packet is encoded transforming data type from double or uint32_t to
 * uint8_t for compatibility with the transceiver. In order to not loose
 * infromation, the decimal numbers are multiplied with a factor and separated
 * in 2 different octets.
 */

void Radio::encode2byte(float number, uint8_t encode_bytes[])
{
	int aux = (int) (number*100);
	uint8_t HB = aux >> 8;			//Number High Byte
	uint8_t LB = aux;				//Number Low Byte

	encode_bytes[0] = HB;
	encode_bytes[1] = LB;
}

void Radio::encode2byteD(double number, uint8_t encode_bytes[])
{
	int aux = (int) (number*100);
	uint8_t HB = aux >> 8;			//Number High Byte
	uint8_t LB = aux;				//Number Low Byte

	encode_bytes[0] = HB;
	encode_bytes[1] = LB;
}

void Radio::encode3byte(double number, uint8_t encode_bytes[])
{
	int aux = (int) (number*100);
	uint8_t HB = aux >> 16;
	uint8_t MB = aux >> 8;
	uint8_t LB = aux;

	encode_bytes[0] = HB;
	encode_bytes[1] = MB;
	encode_bytes[2] = LB;
}

void Radio::encodeFrame(double dataD[], float dataF[], uint8_t frame[])
{
	// Double data
	uint8_t num1_bytes[2];
    uint8_t num2_bytes[3];
    uint8_t num3_bytes[3];
    // Float data
    uint8_t num4_bytes[2];
    uint8_t num5_bytes[2];
    uint8_t num6_bytes[2];
    uint8_t num7_bytes[2];
    uint8_t num8_bytes[2];

    // Double data
    encode2byteD(dataD[0], num1_bytes);
    encode3byte(dataD[1], num2_bytes);
    encode3byte(dataD[2], num3_bytes);
    // Float data
    encode2byte(dataF[0], num4_bytes);
    encode2byte(dataF[1], num5_bytes);
    encode2byte(dataF[2], num6_bytes);
    encode2byte(dataF[3], num7_bytes);
    encode2byte(dataF[4], num8_bytes);

    // Generate Frame
    frame[0] = num1_bytes[0];
    frame[1] = num1_bytes[1];
    
    frame[2] = num2_bytes[0];
    frame[3] = num2_bytes[1];
    frame[4] = num2_bytes[2];
    
    frame[5] = num3_bytes[0];
    frame[6] = num3_bytes[1];
    frame[7] = num3_bytes[2];
    
    frame[8] = num4_bytes[0];
    frame[9] = num4_bytes[1];
    
    frame[10] = num5_bytes[0];
    frame[11] = num5_bytes[1];

	frame[12] = num6_bytes[0];
    frame[13] = num6_bytes[1];

	frame[14] = num7_bytes[0];
    frame[15] = num7_bytes[1];

	frame[16] = num8_bytes[0];
    frame[17] = num8_bytes[1];
}

void Radio::send_data(double dataD[], float dataF[])
{
	uint8_t frame[18];
	encodeFrame(dataD, dataF, frame);
	sendFrame(frame, sizeof(frame));
}