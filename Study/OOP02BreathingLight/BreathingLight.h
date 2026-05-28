// #ifndef  BREATHING_LIGHT_H
#pragma once
#define BREATHING_LIGHT_H
#include "Arduino.h"
class BreathingLight{
  private:
    byte _pin;
    unsigned long _interval;
    unsigned long _lastTime;
    int _brightness;  // 记录灯的当前亮度 (0 ~ 255)
    int _fadeAmount;  // 每次亮度的变化量（正数代表变亮，负数代表变暗）
  public:
    BreathingLight(byte pin, unsigned long interval);

    void begin();
    void update();
};
// #endif