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
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(rest1, OUTPUT);
  pinMode(rest2, OUTPUT);
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  myservo1_.attach(sigS1);
  myservo2_.attach(sigS2);
  digitalWrite(enable1, LOW);
  digitalWrite(enable2, LOW);
  digitalWrite(rest1, LOW);
  digitalWrite(rest2, LOW);
  digitalWrite(servo1, LOW);
  digitalWrite(servo2, LOW);
  myservo1_.write(start_s1);
  myservo2_.write(start_s2);
}

void DPL::Rdpl1_start(void)
{
  digitalWrite(enable1, HIGH);
  digitalWrite(rest1, HIGH);
}

void DPL::Rdpl1_end(void)
{
  digitalWrite(enable1, LOW);
  digitalWrite(rest1, LOW);
}

void DPL::Rdpl2_start(void)
{
  digitalWrite(enable2, HIGH);
  digitalWrite(rest2, HIGH);
}

void DPL::Rdpl2_end(void)
{
  digitalWrite(enable2, LOW);
  digitalWrite(rest2, LOW);
}

void DPL::Act_s1(void)
{
  digitalWrite(enable1, HIGH);
  digitalWrite(servo1, HIGH);
  myservo1_.write(end_m1);
  delay(10000);
  digitalWrite(enable1, LOW);
  digitalWrite(servo1, LOW);
}

void DPL::Act_s2(void)
{
  digitalWrite(enable2, HIGH);
  digitalWrite(servo2, HIGH);
  myservo2_.write(end_m2);
  delay(10000);
  digitalWrite(enable2, LOW);
  digitalWrite(servo2, LOW);
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
  digitalWrite(enable1, LOW);
  digitalWrite(enable2, LOW);
  digitalWrite(rest1, LOW);
  digitalWrite(rest2, LOW);
  digitalWrite(servo1, LOW);
  digitalWrite(servo2, LOW);
  myservo1_.write(start_s1);
  myservo2_.write(start_s2);
}
