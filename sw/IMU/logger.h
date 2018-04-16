#include "Arduino.h"
#define DEBUG_LEVEL 1
// Debug
/*#if (DEBUG_LEVEL)
#define DEBUG_PRINTLN(...) {Serial.print("D/"); Serial.println(__VA_ARGS__);}
#define DEBUG_PRINT(...) {Serial.print("D/"); Serial.print(__VA_ARGS__);}
#else
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)
#endif*/
#define DEBUG2_PRINTLN(...) {Serial.print("D/"); Serial.println(__VA_ARGS__);}
#define DEBUG2_PRINT(...) {Serial.print("D/"); Serial.print(__VA_ARGS__);}