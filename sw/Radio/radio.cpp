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

float Radio::decode2byte(uint8_t byte1, uint8_t byte2)
{
    int aux = byte1;
    aux = (aux << 8) + byte2;
    return aux/100.0;
}

void Radio::encode2byteD(double number, uint8_t encode_bytes[])
{
	int aux = (int) (number*100);
	uint8_t HB = aux >> 8;			//Number High Byte
	uint8_t LB = aux;				//Number Low Byte

	encode_bytes[0] = HB;
	encode_bytes[1] = LB;
}

double Radio::decode2byteD(uint8_t byte1, uint8_t byte2)
{
    int aux = byte1;
    aux = (aux << 8) + byte2;
    return aux/100.0;
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

double Radio::decode3byte(uint8_t byte1, uint8_t byte2, uint8_t byte3)
{
    int aux = byte1;
    aux = (aux << 8) + byte2;
    aux = (aux << 8) + byte3;
    return aux/100.0;
}

void Radio::encode(double dataD[], float dataF[], uint8_t frame[])
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

void Radio::decode(uint8_t frame[], double dataD[], float dataF[])
{
    // Double data
    dataD[0] = decode2byteD(frame[0], frame[1]);
    dataD[1] = decode3byte(frame[2], frame[3], frame[4]);
    dataD[2] = decode3byte(frame[5], frame[6], frame[7]);
    // Float data
    dataF[0] = decode2byte(frame[8], frame[9]);
    dataF[1] = decode2byte(frame[10], frame[11]);
    dataF[2] = decode2byte(frame[12], frame[13]);
    dataF[3] = decode2byte(frame[14], frame[15]);
    dataF[4] = decode2byte(frame[16], frame[17]);
}

void Radio::send_data(double dataD[], float dataF[])
{
	uint8_t frame[18];
	encode(dataD, dataF, frame);
	sendFrame(frame, sizeof(frame));
}

void Radio::read_data(double dataD[], float dataF[])
{
    uint8_t frame[18];
    if (rf22.available())
    {
        uint8_t len = sizeof(frame);
        uint8_t from;
        if (rf22.recvfromAck(frame, &len, &from))
        {
            decode(frame, dataD, dataF);
        }
    }
}