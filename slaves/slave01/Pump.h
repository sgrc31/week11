/*
  Pump.h
  Created by Pietro Rustici, 14 April, 2017.
  Released into the public domain.
*/
#ifndef Pump_h
#define Pump_h

#include "Arduino.h"

class Pump
{
  public:
    Pump(int enable,int step, int dir);
    void flow(int steps);
    void clean();
  private:
    int _enable;
    int _step;
    int _dir;
};

#endif
