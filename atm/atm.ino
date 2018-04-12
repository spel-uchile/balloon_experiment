#include <Wire.h>
#include <SFE_BMP180.h>
#include "SparkFun_Si7021_Breakout_Library.h"

//Create an instance of the object
SFE_BMP180 pressure;
Weather sensor;

void setup()
{
  Wire.begin();        // Join i2c bus
  Serial.begin(9600);  // Start serial for output
  pressure.begin();
}

void loop()
{
  char status;
  double T,P,p0,a;  

  status = pressure.startTemperature();
  delay(status);
  status = pressure.getTemperature(T);
  status = pressure.startPressure(3);
  delay(status);
  status = pressure.getPressure(P,T);
  p0 = 1013.25; 
  a = pressure.altitude(P,p0);
  
  delay(400);  

  float humidity = sensor.getRH();
  float tempC = sensor.getTemp();
 
  delay(400);
  
  Serial.print("  Temp(c):");
  Serial.print(T,1);
  Serial.print("  Pressure(hPa):");
  Serial.print(P,1);
  Serial.print("  Altitude(m):");
  Serial.print(a,0);  
  Serial.print("  Temp(c):");
  Serial.print(tempC);
  Serial.print("  Humidity (%):");
  Serial.print(humidity); 
  Serial.println();  
}
