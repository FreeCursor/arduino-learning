#include "Arduino.h"
#include "BL.h"
BL::BL(byte pin,unsigned long interval){
  _pin=pin;
  _interval=interval;
  _angle=0.0f;
 _lastTime=0; 
}

void BL::begin(){
  pinMode(_pin, OUTPUT);
}
void BL::update(){
  unsigned long currentTime=millis();
  if(currentTime-_lastTime>=_interval){
    _lastTime=currentTime;
    _angle+=0.05f;
    if(_angle>=6.28318){ //2*pi 约为6.28318
      _angle=0.0f;
    }
    float brightness=127.5+127.5*sin(_angle);
    brightness=constrain((int)brightness, 0, 255);
    analogWrite(_pin, brightness);
  }
}