/**
 * @brief Simple IMU Library
 */
 
/*Author: Gustavo Diaz*/

#include "imu.h"

//-------------------------- Public Methods --------------------------

void IMU9250::init(void)
{
	// Call imu_.begin() to verify communication and initialize
	if (imu_.begin() != INV_SUCCESS)
	{
		ERROR_PRINTLN_RAW("Unable to communicate with MPU-9250");
		ERROR_PRINTLN_RAW("Check connections, and try again.");
	}

	imu_.dmpBegin(DMP_FEATURE_6X_LP_QUAT | // Enable 6-axis quat
	DMP_FEATURE_GYRO_CAL, // Use gyro calibration
	10); // Set DMP FIFO rate to 10 Hz
	// DMP_FEATURE_LP_QUAT can also be used. It uses the 
	// accelerometer in low-power mode to estimate quat's.
	// DMP_FEATURE_LP_QUAT and 6X_LP_QUAT are mutually exclusive
}

void IMU9250::updateData(void)
{
	// Check for new data in the FIFO
	if ( imu_.fifoAvailable() )
	{
		// Use dmpUpdateFifo to update the ax, gx, mx, etc. values
		if ( imu_.dmpUpdateFifo() == INV_SUCCESS)
		{
			// computeEulerAngles can be used -- after updating the
			// quaternion values -- to estimate roll, pitch, and yaw
			imu_.computeEulerAngles();
			imuData.qw = imu_.qw;
			imuData.qx = imu_.qx;
			imuData.qy = imu_.qy;
			imuData.qz = imu_.qz;
			imuData.roll = imu_.roll;
			imuData.pitch = imu_.pitch;
			imuData.yaw = imu_.yaw;
			imuData.gx = 0;/*To Do: add this data*/
			imuData.gy = 0;
			imuData.gz = 0;
			imuData.mx = 0;
			imuData.my = 0;
			imuData.mz = 0;
		}
	}
}

void IMU9250::infoPrint(void)
{
    INFO_PRINTLN_RAW("time\tqw\tqx\tqy\tqz\troll\tpitch\tyaw\tgx\tgy\tgz\tmx\tmy\tmz");
    INFO_PRINT_RAW(imu_.time);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.qw);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.qx);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.qy);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.qz);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.roll);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.pitch);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.yaw);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.gx);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.gy);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.gz);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.mx);INFO_PRINT_RAW("\t");
    INFO_PRINT_RAW(imuData.my);INFO_PRINT_RAW("\t");
    INFO_PRINTLN_RAW(imuData.mz);
}