/**
 * @brief Simple GPS Library
 */

/*Author: Matias Vidal*/

/*Requiered Libraries*/
#include <Arduino.h>
#include <TinyGPS++.h>

/**
 * @class GPS
 * @brief Class for manage GPS data
 */

 class GPS {
    /*Private Members*/
    
    // GPS object
    TinyGPSPlus gps;

    public:
        /*Public Members*/
        double lat, lng, alt, crse, mps;
        uint8_t hour, minute, second, sat;
        
        // Default constructor
        GPS();
        
        // Overload constructor
        GPS(int);

        // Mutator functions
        void init(void);

        void updateData(void);

    private:
        int gps_baudrate;
    
 };

