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
    if (!rf22.sendtoWait(frame, frame_size, addr2_))
        Serial.println(F("sendtoWait failed"));
}

/**
 * The packet is encoded transforming data type from double or float to
 * uint8_t for compatibility with the transceiver. In order to not loose
 * information, the decimal numbers are multiplied with a factor and separated
 * in 2, 3 or 4 different octets.
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

void Radio::encode4byteD(double number, uint8_t encode_bytes[]) {
    int aux = (int) (number*1000000);
    uint8_t HB = aux >> 24;
    uint8_t M1B = aux >> 16;
    uint8_t M2B = aux >> 8;
    uint8_t LB = aux;

    encode_bytes[0] = HB;
    encode_bytes[1] = M1B;
    encode_bytes[2] = M2B;
    encode_bytes[3] = LB;
}

double Radio::decode4byteD(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4) {
    int aux = byte1;
    aux = (aux << 8) + byte2;
    aux = (aux << 8) + byte3;
    aux = (aux << 8) + byte4;
    return aux/1000000.0;
}

void Radio::encode(double dataD[], float dataF[], uint8_t dataU[], uint8_t frame[])
{
    // Double data
    uint8_t num1_bytes[2];
    uint8_t num2_bytes[3];
    uint8_t num3_bytes[3];
    uint8_t num4_bytes[4];
    uint8_t num5_bytes[4];
    uint8_t num6_bytes[2];
    uint8_t num7_bytes[2];
    uint8_t num8_bytes[2];
    // Float data
    uint8_t num9_bytes[2];
    uint8_t num10_bytes[2];
    uint8_t num11_bytes[2];
    uint8_t num12_bytes[2];
    uint8_t num13_bytes[2];

    // Double data
    encode2byteD(dataD[0], num1_bytes);
    encode3byte(dataD[1], num2_bytes);
    encode3byte(dataD[2], num3_bytes);
    encode4byteD(dataD[3], num4_bytes);
    encode4byteD(dataD[4], num5_bytes);
    encode2byteD(dataD[5], num6_bytes);
    encode2byteD(dataD[6], num7_bytes);
    encode2byteD(dataD[7], num8_bytes);
    // Float data
    encode2byte(dataF[0], num9_bytes);
    encode2byte(dataF[1], num10_bytes);
    encode2byte(dataF[2], num11_bytes);
    encode2byte(dataF[3], num12_bytes);
    encode2byte(dataF[4], num13_bytes);

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
    frame[10] = num4_bytes[2];
    frame[11] = num4_bytes[3];

    frame[12] = num5_bytes[0];
    frame[13] = num5_bytes[1];
    frame[14] = num5_bytes[2];
    frame[15] = num5_bytes[3];

    frame[16] = num6_bytes[0];
    frame[17] = num6_bytes[1];

    frame[18] = num7_bytes[0];
    frame[19] = num7_bytes[1];

    frame[20] = num8_bytes[0];
    frame[21] = num8_bytes[1];

    frame[22] = num9_bytes[0];
    frame[23] = num9_bytes[1];

    frame[24] = num10_bytes[0];
    frame[25] = num10_bytes[1];

    frame[26] = num11_bytes[0];
    frame[27] = num11_bytes[1];

    frame[28] = num12_bytes[0];
    frame[29] = num12_bytes[1];

    frame[30] = num13_bytes[0];
    frame[31] = num13_bytes[1];

    frame[32] = dataU[0];
    frame[33] = dataU[1];
    frame[34] = dataU[2];
    frame[35] = dataU[3];
}

void Radio::decode(uint8_t frame[], double dataD[], float dataF[], uint8_t dataU[])
{
    // Double data
    dataD[0] = decode2byteD(frame[0], frame[1]);
    dataD[1] = decode3byte(frame[2], frame[3], frame[4]);
    dataD[2] = decode3byte(frame[5], frame[6], frame[7]);
    dataD[3] = decode4byteD(frame[8], frame[9], frame[10], frame[11]);
    dataD[4] = decode4byteD(frame[12], frame[13], frame[14], frame[15]);
    dataD[5] = decode2byteD(frame[16], frame[17]);
    dataD[6] = decode2byteD(frame[18], frame[19]);
    dataD[7] = decode2byteD(frame[20], frame[21]);
    // Float data
    dataF[0] = decode2byte(frame[22], frame[23]);
    dataF[1] = decode2byte(frame[24], frame[25]);
    dataF[2] = decode2byte(frame[26], frame[27]);
    dataF[3] = decode2byte(frame[28], frame[29]);
    dataF[4] = decode2byte(frame[30], frame[31]);
    // Uint8_t data
    dataU[0] = frame[32];
    dataU[1] = frame[33];
    dataU[2] = frame[34];
    dataU[3] = frame[35];
}

void Radio::send_data(double dataD[], float dataF[], uint8_t dataU[])
{
    uint8_t frame[35];
    encode(dataD, dataF, dataU, frame);
    sendFrame(frame, sizeof(frame));
}

void Radio::read_data(double dataD[], float dataF[], uint8_t dataU[])
{
    uint8_t frame[35];
    if (rf22.available())
    {
        uint8_t len = sizeof(frame);
        uint8_t from;
        if (rf22.recvfromAck(frame, &len, &from))
        {
            decode(frame, dataD, dataF);
            displayData(dataD, dataF, dataU);
        }
    }
}

void Radio::displayData(double dataD[], float dataF[], uint8_t dataU[]) {
    Serial.print("Temp: ");
    Serial.print(dataD[0]);
    Serial.print("    Pressure: ");
    Serial.print(dataD[1]);
    Serial.print("    Altitude: ");
    Serial.print(dataD[2]);
    
    Serial.print("    TempC: ");
    Serial.print(dataF[0]);
    Serial.print("    Humidity: ");
    Serial.print(dataF[1]);
    Serial.print("    IMU0: ");
    Serial.print(dataF[2]);
    Serial.print("    IMU1: ");
    Serial.print(dataF[3]);
    Serial.print("    IMU2: ");
    Serial.println(dataF[4]);

    Serial.print("HH:MM:SS: ");
    Serial.print(dataU[0]);
    Serial.print(":");
    Serial.print(dataU[1]);
    Serial.print(":");
    Serial.print(dataU[2]);
    Serial.print("    Sat: ");
    Serial.print(dataU[3]);
    Serial.print("    Location: ");
    Serial.print(dataD[3], 6);
    Serial.print(",");
    Serial.print(dataD[4], 6);
    Serial.print("    Altitude (GPS): ");
    Serial.print(dataD[5]);
    Serial.print("    Course: ");
    Serial.print(dataD[6]);
    Serial.print("    Speed: ");
    Serial.println(dataD[7]);
}
