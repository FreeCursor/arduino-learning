#include <stdint.h>
#pragma once
#include <Arduino.h>

class DebounceButton{
  public:
  DebounceButton(uint8_t);

  void begin();
  void wasPressed();

private:
  uint8_t _pin;
  uint32_t duration;
  uint32_t _lastDebounceTime;
  bool lastState;
  bool stableState;
};