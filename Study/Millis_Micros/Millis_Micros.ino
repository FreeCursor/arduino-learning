// millis()  毫秒
// micros()  微秒

const int ledPin=9;
unsigned  long  previousMillis=0;
const long interval=1000;
int ledState=LOW;

void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // millis() 是板子从通电/复位开始的时间(毫秒)
  unsigned long currentMillis=millis();

  if(currentMillis-previousMillis>interval){
    previousMillis=currentMillis;

    ledState=!ledState;

    digitalWrite(ledPin,ledState);
  }

}
