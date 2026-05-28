#pragma once 
#include "Arduino.h"
class BL{
  private:
    byte _pin;
    unsigned long _interval;
    unsigned long _lastTime;
    float _angle;

  public:
    BL(byte ,unsigned long);
    void begin();
    void update();
};
