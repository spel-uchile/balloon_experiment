#include "dpl.h"
#include "pines.h"

DPL dpl;

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================


void setup() {
        Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps
        dpl.init();
        funciones();
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {

        // Definición del sistema de funciones:
        // 1) Activa resistencia 1
        // 2) Activa resistencia 2
        // 3) Activa motor 1
        // 4) Activa motor 2
        // 5) Demostración despliegue 1
        // 6) Demostración despliegue 2
        
        if (Serial.available() > 0) {
                // read the incoming byte:
                char incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);

                if (incomingByte == '0')
                {
                  funciones();
                }
                else if (incomingByte == '1')
                {
                  dpl.Rdpl1_start();
                }
                else if (incomingByte == '2')
                {
                  dpl.Rdpl2_start();
                }
                else if (incomingByte == '3')
                {
                  dpl.Rdpl1_end();
                }
                else if (incomingByte == '4')
                {
                  dpl.Rdpl2_end();
                }
                else if (incomingByte == '5')
                {
                  dpl.Act_s1();
                }
                else if (incomingByte == '6')
                {
                  dpl.Act_s2();                  
                }
                
                else if (incomingByte == '7')
                {
                  dpl.dem1();
                }
                else if (incomingByte == '8')
                {
                  dpl.dem2();
                }  
                else if (incomingByte == '9')
                {
                  dpl.restart();
                }                                                

        }
}


void funciones()
{
  Serial.println(F("Definición del sistema de funciones:"));
  Serial.println(F("0) Lista de comandos"));
  Serial.println(F("1) Activa resistencia 1"));
  Serial.println(F("2) Activa resistencia 2"));
  Serial.println(F("3) Desactiva resistencia 1"));
  Serial.println(F("4) Desactiva resistencia 2"));
  Serial.println(F("5) Activa motor 1"));
  Serial.println(F("6) Activa motor 2"));
  Serial.println(F("7) Demostración despliegue 1"));
  Serial.println(F("8) Demostración despliegue 2"));
  Serial.println(F("9) Reiniciar"));
}

