#include "ButtonDebounce.h"

DebounceButton::DebounceButton(uint8_t pin){
  _pin=pin;
  _lastDebounceTime=0;
}