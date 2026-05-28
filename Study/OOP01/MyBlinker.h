// 头文件设计
#ifndef MY_BLINKER_H    //预处理哨兵防止头文件被重复包含报错
#define MY_BLINKER_H

#include "Arduino.h"

class MyBlinker{
  private:
    byte _pin;
    unsigned long _interval;
    unsigned long _lastTime;
    bool _state;

  public:
    MyBlinker(byte pin, unsigned long interval);
      void begin();

      void update();
};
#endif