#include "Arduino.h"
#include "BreathingLight.h"

BreathingLight::BreathingLight(byte pin,unsigned long interval){
  _pin=pin;
  _interval=interval;
  _lastTime=0;

  _brightness = 0;   // 刚通电时，亮度为 0
  _fadeAmount = 2;    // 每次时间到了，亮度增加 n（这个值越大，呼吸得越急促）
}
void BreathingLight::begin(){
  pinMode(_pin,OUTPUT);
  analogWrite(_pin, 0);
}

void BreathingLight::update(){
  unsigned long currentTIme=millis();
  if(currentTIme-_lastTime>=_interval){
    _lastTime=currentTIme;
    _brightness+=_fadeAmount;
    
    if (_brightness <= 0 || _brightness >= 255) {    //取反步长，变暗
      _fadeAmount = -_fadeAmount; // 正 5 变 负 5（开始变暗），或 负 5 变 正 5（开始变亮）
    }
    _brightness = constrain(_brightness, 0, 255);
    analogWrite(_pin,_brightness);
  }
}