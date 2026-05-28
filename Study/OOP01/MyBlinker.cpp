#include "MyBlinker.h" // 必须包含你刚刚写的头文件

// 在 C++ 中，实现类方法时必须加上 "类名::" 作用域解析符，否则编译器不知道这个函数属于谁！
MyBlinker::MyBlinker(byte pin, unsigned long interval) {
  _pin = pin;
  _interval = interval;
  _lastTime = 0;
  _state = LOW;
}

void MyBlinker::begin() {
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, _state);
}

void MyBlinker::update() {
  unsigned long currentTime = millis();
  if (currentTime - _lastTime >= _interval) {
    _lastTime = currentTime;
    _state = !_state;
    digitalWrite(_pin, _state);
  }
}