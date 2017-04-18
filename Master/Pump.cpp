/*
  Pump.cpp
  Created by Pietro Rustici, 14 April, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Pump.h"

Pump::Pump(int enable,int step, int dir)
{
  pinMode(enable, OUTPUT);
  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);
  _enable = enable;
  _step = step;
  _dir = dir;
}

void Pump::flow(int steps)
{
   digitalWrite(_enable,LOW);
   digitalWrite(_dir,HIGH);
   for(int i=0;i<steps;i++)
   {
      digitalWrite(_step,HIGH);
      delay(5);
      digitalWrite(_step,LOW);
      delay(5);
   }
}

void Pump::clean()
{
  digitalWrite(_step, HIGH);
  delay(1000);
  digitalWrite(_step, LOW);
  delay(250);
}
