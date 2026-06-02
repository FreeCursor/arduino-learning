// Static Local Variables
// learn static function

// debounce button
bool readButtonDebounced(int pin) {
  // init once 
  static unsigned long lastDebounceTime = 0; 
  static int lastButtonState = HIGH;
  static int stableState = HIGH;

  int reading = digitalRead(pin);
  unsigned long currentTime = millis();

  // if level changes, reset timer
  if (reading != lastButtonState) {
    lastDebounceTime = currentTime;
  }

  // stable time>50ms --- confirm the new state
  if ((currentTime - lastDebounceTime) > 50) {
    if (reading != stableState) {
      stableState = reading;
    }
  }
  // record state
  lastButtonState = reading; 
  // low level denotes switch on
  return (stableState == LOW); 
}


void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  if (readButtonDebounced(2)) {
    Serial.println("Button Pressed!");
  }

}
