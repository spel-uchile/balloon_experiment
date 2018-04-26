#include "gps.h"

/*GPS baudrate*/
#define GPS_BAUDRATE 9600

//Create an instance of the objects
GPS gps;

void setup() {
    Serial.begin(115200);
    // initialize
    gps.init();
    delay(500);
}

void loop() {
    gps.updateData();
    Serial.print("Latitude,Longitude: ");
    Serial.print(gps.lat, 6);
    Serial.print(",");
    Serial.print(gps.lng, 6);
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
    delay(500);
}
