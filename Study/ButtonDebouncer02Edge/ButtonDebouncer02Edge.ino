// about the Static Local Variables

// function of checking button
bool ButtonState(byte pin){
  // only run once when initiate
  static unsigned long lastDebounceTime = 0; 
  static unsigned long pressStartTime = 0;
  static bool lastState = HIGH;  // switch open HIGH .  close LOW
  static bool stableState = HIGH; 
  static bool isPressing = false;

  byte pinReading=digitalRead(pin);
  unsigned long currentTime=millis();

  if (pinReading != lastState) {
    lastDebounceTime = currentTime; // any changes, reset timer
  }

  if((currentTime-lastDebounceTime)>=40){
    // use && may cause logic error in complex program
    // robustness ！！
    if(pinReading!=stableState){
      stableState=pinReading;
    }
  }
  lastState=pinReading;  
  // 1st if statement will excute if reading is changing
  // without this code the 1st if statement will be skipped
  return (stableState==LOW);  // switch closed
}
void setup() {

  pinMode(5, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(ButtonState(5)){
    Serial.println("Button pressed");
  }
}
