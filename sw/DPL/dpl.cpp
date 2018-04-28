/**
 * @brief Simple ballon deploy Library
 */
 
/*Author: Cristobal Garrido*/

#include "dpl.h"
#include "pines.h"
#include "arduino.h" 

#define DEBUG_LEVEL 1

//-------------------------- Public Methods --------------------------

void DPL::init(void)
{
  pinMode(ENABLE1, OUTPUT);
  pinMode(ENABLE2, OUTPUT);
  pinMode(REST1, OUTPUT);
  pinMode(REST2, OUTPUT);
  pinMode(SERVO1, OUTPUT);
  pinMode(SERVO2, OUTPUT);
  myservo1_.attach(SIG_S1);
  myservo2_.attach(SIG_S2);
  digitalWrite(ENABLE1, LOW);
  digitalWrite(ENABLE2, LOW);
  digitalWrite(REST1, LOW);
  digitalWrite(REST2, LOW);
  digitalWrite(SERVO1, LOW);
  digitalWrite(SERVO2, LOW);
  myservo1_.write(start_s1);
  myservo2_.write(start_s2);
}

void DPL::Rdpl1_start(void)
{
  digitalWrite(ENABLE1, HIGH);
  digitalWrite(REST1, HIGH);
}

void DPL::Rdpl1_end(void)
{
  digitalWrite(ENABLE1, LOW);
  digitalWrite(REST1, LOW);
}

void DPL::Rdpl2_start(void)
{
  digitalWrite(ENABLE2, HIGH);
  digitalWrite(REST2, HIGH);
}

void DPL::Rdpl2_end(void)
{
  digitalWrite(ENABLE2, LOW);
  digitalWrite(REST2, LOW);
}

void DPL::Act_s1(void)
{
  digitalWrite(ENABLE1, HIGH);
  digitalWrite(SERVO1, HIGH);
  myservop1_.write(end_m1);
  delay(10000);
  digitalWrite(ENABLE1, LOW);
  digitalWrite(SERVO1, LOW);
}

void DPL::Act_s2(void)
{
  digitalWrite(ENABLE2, HIGH);
  digitalWrite(SERVO2, HIGH);
  myservo2_.write(end_m2);
  delay(10000);
  digitalWrite(ENABLE2, LOW);
  digitalWrite(SERVO2, LOW);
}

void DPL::dem1(void)
{
  Rdpl1_start();
  delay(80000);
  Rdpl1_end();
  delay(60000);
  Rdpl1_start();
  delay(80000);
  Rdpl1_end();
  Act_s1();
}

void DPL::dem2(void)
{
  Rdpl2_start();
  delay(80000);
  Rdpl2_end();
  delay(60000);
  Rdpl2_start();
  delay(80000);
  Rdpl2_end();
  Act_s2();
}

void DPL::restart(void)
{
  digitalWrite(ENABLE1, LOW);
  digitalWrite(ENABLE2, LOW);
  digitalWrite(REST1, LOW);
  digitalWrite(REST2, LOW);
  digitalWrite(SERVO1, LOW);
  digitalWrite(SERVO2, LOW);
  myservo1_.write(start_s1);
  myservo2_.write(start_s2);
}
