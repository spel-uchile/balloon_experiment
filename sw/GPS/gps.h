/**
 * @brief Simple GPS Library
 */

/*Author: Matias Vidal*/

/*Requiered Libraries*/
#include <Arduino.h>
#include <TinyGPS++.h>
#include "gps_data.h"
#include "logger.h"

/**
 * @class GPS
 * @brief Class for manage GPS data
 */

 class GPS {
    /*Private Members*/
    
    // GPS object
    TinyGPSPlus gps;
    // Serial port
    HardwareSerial *serial_port_;

    public:
        /*Public Members*/
        GpsData gpsData;
        
        // Default constructor
        GPS(void);
        
        // Overload constructor
        GPS(HardwareSerial *serial_port, int baudrate);

        // Mutator functions
        void init(void);
        void updateData(void);
        void checkValidity(void);

    private:
        int gps_baudrate_;
 };