/**
 * @brief Simple Raspberry Pi communication Library
 */

/*Author: Matías Vidal*/

/*Requiered Libraries*/
#include "rpycom.h"

void RPYCOM::updateBeacom(double dataD[], float dataF[], uint8_t dataU8[], uint32_t dataU32)
{   
    beacon_tx_.Temp1 = (float) dataD[0];
    beacon_tx_.Pressure = (float) dataD[1];
    beacon_tx_.Alt = (float) dataD[2];
    beacon_tx_.Temp2 = dataF[0];
    beacon_tx_.Humidity = dataF[1];
    beacon_tx_.Temp3 = dataF[2];
    beacon_tx_.IMU1 = dataF[3;
    beacon_tx_.IMU2 = dataF[4];
    beacon_tx_.IMU3 = dataF[5];
    beacon_tx_.GPS_Lat = (float) dataD[3];
    beacon_tx_.GPS_Lng = (float) dataD[4];
    beacon_tx_.GPS_Alt = (float) dataD[5];
    beacon_tx_.GPS_Crse = (float) dataD[6];
    beacon_tx_.GPS_Speed = (float) dataD[7];
    beacon_tx_.GPS_HH = dataU8[0];
    beacon_tx_.GPS_MM = dataU8[1];
    beacon_tx_.GPS_SS = dataU8[2];
    beacon_tx_.GPS_validity = dataU8[3];
    beacon_tx_.GPS_Sat = dataU32;
}

void RPYCOM::BeacomTest()
{   
    beacon_tx_.Temp1 = 123.45;
    beacon_tx_.Pressure = 956.76;
    beacon_tx_.Alt = -75.01;
    beacon_tx_.Temp2 = 123.45;
    beacon_tx_.Humidity = 956.76;
    beacon_tx_.IMU1 = -75.01;
    beacon_tx_.IMU2 = -75.01;
    beacon_tx_.IMU3 = -75.01;
    beacon_tx_.GPS_Lat = 98.3;
    beacon_tx_.GPS_Lng = 21.7;
    beacon_tx_.GPS_Alt = 87.80;
    beacon_tx_.GPS_Crse = 101.71;
    beacon_tx_.GPS_Speed = 43.87;
    beacon_tx_.GPS_HH = 241;
    beacon_tx_.GPS_MM = 32;
    beacon_tx_.GPS_SS = 85;
    beacon_tx_.GPS_validity = 255;
    beacon_tx_.GPS_Sat = 4294967295;
}

void RPYCOM::getData()
{
	hw_port_->readBytes((char*)&cmd_, cmd_size_);
    hw_port_->readBytes((char*)&beacon_rx_, beacon_tx_size_);
    hw_port_->readBytes((char*)&data_, DATA_SZ);
}

void RPYCOM::sendData()
{
	uint8_t padd_sz = 253-beacon_tx_size_;
	uint8_t padding[padd_sz];
	memset(padding, 0, padd_sz);

	hw_port_->write(node_);
	hw_port_->write(port_);
	hw_port_->write((uint8_t *)&beacon_tx_, beacon_tx_size_);
	hw_port_->write(padding, padd_sz);
	Serial.println(sizeof(beacon_tx_));
	Serial.println(sizeof(padding));
}
