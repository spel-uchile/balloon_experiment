#include "pines_balloon.h"
#include "gps.h"

/*GPS baudrate*/
#define GPS_BAUDRATE 9600

//Create an instance of the objects
GPS gps;

void setup()
{
    // Wire.begin();        // Join i2c bus  
    Serial.begin(115200);
    // initialize
    gps.init();
}

void loop() {}
    gps.updateData();
    Serial.print("Latitude: ");
    Serial.print(gps.lat);
    Serial.print("    Longitude: ");
    Serial.print(gps.lng);
    Serial.print("      Altitude (m): ");
    Serial.print(gps.alt);
    Serial.print("      Course: ");
    Serial.print(gps.crse);
    Serial.print("      Speed (m/s): ");
    Serial.print(gps.mps);
    Serial.print("      Time: ");
    Serial.print(gps.hour);
    Serial.print(":");
    Serial.print(gps.minute);
    Serial.print(":");
    Serial.print(gps.second);
    Serial.print("      Satellites: ");
    Serial.println(gps.sat);
}
