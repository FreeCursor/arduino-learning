// 模拟输入 input 不需要在setup里配置A0-A5

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sencorValue=analogRead(A0); // 读取A0引脚的电压
  Serial.println(sencorValue);
  delay(3000);
}
