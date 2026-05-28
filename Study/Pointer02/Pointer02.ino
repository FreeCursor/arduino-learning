// 错误示范：直接传值（复印件改了，原件没变）
void fakeUpdate(float temp) {
  temp = 25.5; 
}

// 正确示范：传指针（拿着门牌号直接改原件）
void realUpdate(float *tempPtr) {
  *tempPtr = 25.5; // 去这个地址，把里面的值改成 25.5
}

void setup() {
  Serial.begin(9600);
  float currentTemp = 10.0;

  fakeUpdate(currentTemp);
  Serial.println(currentTemp); // 依然输出 10.0，白忙活了

  realUpdate(&currentTemp);    // 把 currentTemp 的地址传进去
  Serial.println(currentTemp); // 成功输出 25.5！
  Serial.println((unsigned long)&currentTemp);
}
void loop(){

}