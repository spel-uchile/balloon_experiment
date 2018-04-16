/**
 * @brief Simple IMU Library
 */
 
/*Author: Gustavo Diaz*/

// #include "imu.h"

// #define DEBUG_LEVEL 1

// //-------------------------- Public Methods --------------------------
// void dmpDataReady()
// {
//     mpuInterrupt = true;
// }
// void IMU::init(void)
// {
//     // join I2C bus (I2Cdev library doesn't do this automatically)
//     #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
//         Wire.begin();
//         Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
//     #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
//         Fastwire::setup(400, true);
//     #endif

//     /*initialize imu*/
//     DEBUG_PRINTLN(F("Initializing I2C devices..."));
//     mpu.initialize();
//     pinMode(interrupt_pin_, INPUT);

//     // verify connection
//     DEBUG_PRINTLN(F("Testing device connections..."));
//     DEBUG_PRINTLN(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

//     // load and configure the DMP
//     DEBUG_PRINTLN(F("Initializing DMP..."));
//     devStatus = mpu.dmpInitialize();

//     // supply your own gyro offsets here, scaled for min sensitivity
//     mpu.setXGyroOffset(220);
//     mpu.setYGyroOffset(76);
//     mpu.setZGyroOffset(-85);
//     mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

//      // make sure it worked (returns 0 if so)
//     if (devStatus == 0) {
//         // turn on the DMP, now that it's ready
//         DEBUG_PRINTLN(F("Enabling DMP..."));
//         mpu.setDMPEnabled(true);

//         // enable Arduino interrupt detection
//         DEBUG_PRINTLN(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
//         attachInterrupt(digitalPinToInterrupt(interrupt_pin_), dmpDataReady, RISING);
//         mpuIntStatus = mpu.getIntStatus();

//         // set our DMP Ready flag so the main loop() function knows it's okay to use it
//         DEBUG_PRINTLN(F("DMP ready! Waiting for first interrupt..."));
//         dmpReady = true;

//         // get expected DMP packet size for later comparison
//         packetSize = mpu.dmpGetFIFOPacketSize();
//     } else {
//         // ERROR!
//         // 1 = initial memory load failed
//         // 2 = DMP configuration updates failed
//         // (if it's going to break, usually the code will be 1)
//         DEBUG_PRINTLN(F("DMP Initialization failed (code "));
//         DEBUG_PRINTLN(devStatus);
//         DEBUG_PRINTLN(F(")"));
//     }
// }

// void IMU::updateData(void)
// {
//     if (!mpuInterrupt && fifoCount < packetSize)
//     {
//         return;
//     }
//     else
//     {
//         // reset interrupt flag and get INT_STATUS byte
//         mpuInterrupt = false;
//         mpuIntStatus = mpu.getIntStatus();

//         // get current FIFO count
//         fifoCount = mpu.getFIFOCount();

//         // check for overflow (this should never happen unless our code is too inefficient)
//         if ((mpuIntStatus & 0x10) || fifoCount == 1024)
//         {
//             // reset so we can continue cleanly
//             mpu.resetFIFO();
//             DEBUG_PRINTLN(F("FIFO overflow!"));

//         // otherwise, check for DMP data ready interrupt (this should happen frequently)
//         }
//         else if (mpuIntStatus & 0x02)
//         {
//             // wait for correct available data length, should be a VERY short wait
//             while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

//             // read a packet from FIFO
//             mpu.getFIFOBytes(fifoBuffer, packetSize);
            
//             // track FIFO count here in case there is > 1 packet available
//             // (this lets us immediately read more without waiting for an interrupt)
//             fifoCount -= packetSize;

//             #ifdef OUTPUT_READABLE_QUATERNION
//                 mpu.dmpGetQuaternion(&q, fifoBuffer);
//             #endif

//             #ifdef OUTPUT_READABLE_YAWPITCHROLL
//                 // display ypr angles in degrees
//                 mpu.dmpGetQuaternion(&q, fifoBuffer);
//                 mpu.dmpGetGravity(&gravity, &q);
//                 mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
//             #endif

//             #ifdef OUTPUT_READABLE_REALACCEL
//                 // display real acceleration, adjusted to remove gravity
//                 mpu.dmpGetQuaternion(&q, fifoBuffer);
//                 mpu.dmpGetAccel(&aa, fifoBuffer);
//                 mpu.dmpGetGravity(&gravity, &q);
//                 mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
//             #endif

//             #ifdef OUTPUT_READABLE_WORLDACCEL
//                 // display initial world-frame acceleration, adjusted to remove gravity
//                 // and rotated based on known orientation from quaternion
//                 mpu.dmpGetQuaternion(&q, fifoBuffer);
//                 mpu.dmpGetAccel(&aa, fifoBuffer);
//                 mpu.dmpGetGravity(&gravity, &q);
//                 mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
//                 mpu.dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &q);
//             #endif
//         }
//     }
// }