#ifndef IMUDATA_H
#define IMUDATA_H

struct ImuData{
    float qw;
    float qx;
    float qy;
    float qz;
    float roll;
    float pitch;
    float yaw;
    int gx;
    int gy;
    int gz;
	int mx;
	int my;
	int mz;
};

#endif