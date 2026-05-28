void setup() {
  // 1.初始串口通信，设置波特率
  // Sereial.begin(波特率);
  Serial.begin(9600);
}

void loop() {

  Serial.println("Hello, Arduino!");
  delay(3000);
}
