// breathing light
const int ledPin=9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(int b=0;b<=225;b++){
    // analogWrite(引脚, 数值)   -->数值对应亮度   1~1023
    analogWrite(ledPin, b);
    delay(5);
  }
  for(int f=225;f>=0;f--){
    analogWrite(ledPin, f);
    delay(5);
  }

}
