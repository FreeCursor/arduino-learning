#include"BL.h"


BL led1{9,10};

void setup() {
  led1.begin();
}

void loop() {
  led1.update();
}
