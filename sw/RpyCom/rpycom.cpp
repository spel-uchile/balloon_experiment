/**
 * @brief Simple Raspberry Pi communication Library
 */

/*Author: Matías Vidal*/

/*Requiered Libraries*/
#include "rpycom.h"

void RPYCOM::updateBeacom(double dataD[], float dataF[], uint8_t dataU8[], uint32_t dataU32)
{   
    beacon_.Temp1 = (float) dataD[0];
    beacon_.Pressure = (float) dataD[1];
    beacon_.Alt = (float) dataD[2];
    beacon_.Temp2 = dataF[0];
    beacon_.Humidity = dataF[1];
    beacon_.IMU1 = dataF[2];
    beacon_.IMU2 = dataF[3];
    beacon_.IMU3 = dataF[4];
    beacon_.GPS_Lat = (float) dataD[3];
    beacon_.GPS_Lng = (float) dataD[4];
    beacon_.GPS_Alt = (float) dataD[5];
    beacon_.GPS_Crse = (float) dataD[6];
    beacon_.GPS_Speed = (float) dataD[7];
    beacon_.GPS_HH = dataU8[0];
    beacon_.GPS_MM = dataU8[1];
    beacon_.GPS_SS = dataU8[2];
    beacon_.GPS_Sat = dataU32;
}

void RPYCOM::BeacomTest()
{   
    beacon_.Temp1 = 123.45;
    beacon_.Pressure = 956.76;
    beacon_.Alt = -75.01;
    beacon_.Temp2 = 123.45;
    beacon_.Humidity = 956.76;
    beacon_.IMU1 = -75.01;
    beacon_.IMU2 = -75.01;
    beacon_.IMU3 = -75.01;
    beacon_.GPS_Lat = 98.3;
    beacon_.GPS_Lng = 21.7;
    beacon_.GPS_Alt = 87.80;
    beacon_.GPS_Crse = 101.71;
    beacon_.GPS_Speed = 43.87;
    beacon_.GPS_HH = 241;
    beacon_.GPS_MM = 32;
    beacon_.GPS_SS = 85;
    beacon_.GPS_Sat = 4294967295;
}

void RPYCOM::getData()
{
    
}

void RPYCOM::sendData()
{
	uint8_t padd_sz = 253-sizeof(beacon_);
	uint8_t padding[padd_sz];
	memset(padding, 0, padd_sz);

	hw_port_->write(node_);
	hw_port_->write(port_);
	hw_port_->write((uint8_t *)&beacon_, beacon_size_);
	hw_port_->write(padding, padd_sz);
	Serial.println(sizeof(beacon_));
	Serial.println(sizeof(padding));
}