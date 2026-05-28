#include "BreathingLight.h"

BreathingLight led1(9,5);
BreathingLight led2(13,20);
void setup() {
  
  led1.begin();
  led2.begin();

}

void loop() {
  led1.update();
  led2.update();

}
