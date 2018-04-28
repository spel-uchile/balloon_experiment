/**
 * @brief Simple ballon deploy Library
 */
 
/*Author: Cristobal Garrido*/

#include "despl.h"
#include "pines.h"
#include "arduino.h" 

#define DEBUG_LEVEL 1

//-------------------------- Public Methods --------------------------

void DESPL::init(void)
{
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(rest1, OUTPUT);
  pinMode(rest2, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  myservo1_.attach(sigM1);
  myservo2_.attach(sigM2);
  digitalWrite(enable1, LOW);
  digitalWrite(enable2, LOW);
  digitalWrite(rest1, LOW);
  digitalWrite(rest2, LOW);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  myservo1_.write(start_m1);
  myservo2_.write(start_m2);
}

void DESPL::Rdesp1_start(void)
{
  digitalWrite(enable1, HIGH);
  digitalWrite(rest1, HIGH);
}

void DESPL::Rdesp1_end(void)
{
  digitalWrite(enable1, LOW);
  digitalWrite(rest1, LOW);
}

void DESPL::Rdesp2_start(void)
{
  digitalWrite(enable2, HIGH);
  digitalWrite(rest2, HIGH);
}

void DESPL::Rdesp2_end(void)
{
  digitalWrite(enable2, LOW);
  digitalWrite(rest2, LOW);
}

void DESPL::Act_m1(void)
{
  digitalWrite(enable1, HIGH);
  digitalWrite(motor1, HIGH);
  myservo1_.write(end_m1);
  delay(10000);
  digitalWrite(enable1, LOW);
  digitalWrite(motor1, LOW);
  
}

void DESPL::Act_m2(void)
{
  digitalWrite(enable2, HIGH);
  digitalWrite(motor2, HIGH);
  myservo2_.write(end_m2);
  delay(10000);
  digitalWrite(enable2, LOW);
  digitalWrite(motor2, LOW);
}

void DESPL::dem1(void)
{
  Rdesp1_start();
  delay(80000);
  Rdesp1_end();
  delay(60000);
  Rdesp1_start();
  delay(80000);
  Rdesp1_end();
  Act_m1();
}

void DESPL::dem2(void)
{
  Rdesp2_start();
  delay(80000);
  Rdesp2_end();
  delay(60000);
  Rdesp2_start();
  delay(80000);
  Rdesp2_end();
  Act_m2();
}

void DESPL::restart(void)
{
  digitalWrite(enable1, LOW);
  digitalWrite(enable2, LOW);
  digitalWrite(rest1, LOW);
  digitalWrite(rest2, LOW);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  myservo1_.write(start_m1);
  myservo2_.write(start_m2);
}
