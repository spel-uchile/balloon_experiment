/**
 * @brief Simple Raspberry Pi communication Library
 */

/*Author: Matías Vidal*/

/*Requiered Libraries*/
#include "rpycom.h"

void OBC::init() {
    
}

void OBC::updateData(double dataD[], float dataF[], uint8_t dataU[], uint32_t sat) {
    frame beacon;
    
    beacon.Temp1 = (float) dataD[0];
    beacon.Pressure = (float) dataD[1];
    beacon.Alt = (float) dataD[2];
    beacon.Temp2 = dataF[0];
    beacon.Humidity = dataF[1];
    beacon.IMU1 = dataF[2];
    beacon.IMU2 = dataF[3];
    beacon.IMU3 = dataF[4];
    beacon.GPS_Lat = (float) dataD[3];
    beacon.GPS_Lng = (float) dataD[4];
    beacon.GPS_Alt = (float) dataD[5];
    beacon.GPS_Crse = (float) dataD[6];
    beacon.GPS_Speed = (float) dataD[7];
    beacon.GPS_HH = dataU[0];
    beacon.GPS_MM = dataU[1];
    beacon.GPS_SS = dataU[2];
    beacon.GPS_Sat = sat;
}

void getData(void* frame) {
    
}

void sendData(void* frame) {
    
}
