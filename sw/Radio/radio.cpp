/**
 * @brief Simple IMU Library
 */
 
/*Author: Gustavo Diaz*/

#include "radio.h"

//-------------------------- Public Methods --------------------------

void Radio::init(void)
{
	digitalWrite(sdn_pin_, LOW);
	delay(1500);
   if (!rf22.init()) {
        INFO_PRINTLN_RAW(F("Initialization failed"));
    }
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(437.225, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    if (!driver.setModemConfig(driver.FSK_Rb2Fd5)) {
        INFO_PRINTLN_RAW(F("Configuration error"));    
    }
    rf22.setRetries(255);
    INFO_PRINTLN_RAW(F("Set Tx Power = RH_RF22_TXPOW_20DB"));
    INFO_PRINTLN_RAW(F("Set configuration = FSK_Rb2Fd5"));  
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
        INFO_PRINTLN_RAW(F("sendtoWait failed"));
}

void Radio::sendData()
{
    sendFrame((uint8_t *)&beacon_tx_, beacon_tx_size_);
}

void Radio::readData() {
    uint8_t frame[100];
    if (rf22.available()) {
        uint8_t len = sizeof(frame);
        uint8_t from;
        if (rf22.recvfromAck(frame, &len, &from)) {
            memcpy(&beacon, frame+2, sizeof(beacon));
            infoPrint();
        }
    }
}

void Radio::updateBeacon(AtmsData *atmsData, GpsData *gpsData, ImuData *imuData)
{   
    beacon_tx_.Temp1 = (float) atmsData->temperature1;
    beacon_tx_.Pressure = (float) atmsData->pressure;
    beacon_tx_.Alt = (float) atmsData->altitude;
    beacon_tx_.Temp2 = atmsData->temperature2;
    beacon_tx_.Humidity = atmsData->humidity;
    beacon_tx_.Temp3 = atmsData->temperatureDallas;
    beacon_tx_.IMU1 = imuData->gx;
    beacon_tx_.IMU2 = imuData->gy;
    beacon_tx_.IMU3 = imuData->gz;
    beacon_tx_.GPS_Lat = (float) gpsData->latitude;
    beacon_tx_.GPS_Lng = (float) gpsData->longitude;
    beacon_tx_.GPS_Alt = (float) gpsData->altitude;
    beacon_tx_.GPS_Crse = (float) gpsData->crse;
    beacon_tx_.GPS_Speed = (float) gpsData->mps;
    beacon_tx_.GPS_HH = gpsData->hour;
    beacon_tx_.GPS_MM = gpsData->minute;
    beacon_tx_.GPS_SS = gpsData->second;
    beacon_tx_.GPS_validity = gpsData->validity;
    beacon_tx_.GPS_Sat = gpsData->satellites;
}

bool Radio::sendCommand(uint8_t cmd)
{
    return rf22.sendtoWait((uint8_t *)&cmd, 1, addr2_);
}

uint8_t Radio::readCommand(uint8_t *cmd)
{
    if (rf22.available())
    {
        uint8_t len;
        uint8_t from;
        rf22.recvfromAck(cmd, &len, &from);
    }
}

void Radio::infoPrint(void) {
    INFO_PRINT_RAW("    Temp1: ");
    INFO_PRINT_RAW(beacon.Temp1);
    INFO_PRINT_RAW("    Pressure: ");
    INFO_PRINT_RAW(beacon.Pressure);
    INFO_PRINT_RAW("    Altitude: ");
    INFO_PRINT_RAW(beacon.Alt);
    
    INFO_PRINT_RAW("    Temp2: ");
    INFO_PRINT_RAW(beacon.Temp2);
    INFO_PRINT_RAW("    Humidity: ");
    INFO_PRINT_RAW(beacon.Humidity);
    INFO_PRINT_RAW("    Temp3: ");
    INFO_PRINT_RAW(beacon.Temp3);
    INFO_PRINT_RAW("    IMU1: ");
    INFO_PRINT_RAW(beacon.IMU1);
    INFO_PRINT_RAW("    IMU2: ");
    INFO_PRINT_RAW(beacon.IMU2);
    INFO_PRINT_RAW("    IMU3: ");
    INFO_PRINTLN_RAW(beacon.IMU3);

    INFO_PRINT_RAW("HH:MM:SS: ");
    INFO_PRINT_RAW(beacon.GPS_HH);
    INFO_PRINT_RAW(":");
    INFO_PRINT_RAW(beacon.GPS_MM);
    INFO_PRINT_RAW(":");
    INFO_PRINT_RAW(beacon.GPS_SS);
    INFO_PRINT_RAW("    Validity: ");
    INFO_PRINT_RAW(beacon.GPS_validity, BIN);
    INFO_PRINT_RAW("    Sat: ");
    INFO_PRINT_RAW(beacon.GPS_Sat);
    INFO_PRINT_RAW("    Location: ");
    INFO_PRINT_RAW(beacon.GPS_Lat, 6);
    INFO_PRINT_RAW(",");
    INFO_PRINT_RAW(beacon.GPS_Lng, 6);
    INFO_PRINT_RAW("    Altitude (GPS): ");
    INFO_PRINT_RAW(beacon.GPS_Alt);
    INFO_PRINT_RAW("    Course: ");
    INFO_PRINT_RAW(beacon.GPS_Crse);
    INFO_PRINT_RAW("    Speed: ");
    INFO_PRINTLN_RAW(beacon.GPS_Speed);
}