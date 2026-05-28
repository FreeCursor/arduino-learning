// 读取数组
int readings[3]={100,200,300};
void setup() {
  Serial.begin(9600);
  int *p=readings;
  for(int i=0;i<=2;i++){
  Serial.println(*p);
  p++;
  // 输出 100 (第一个元素)
  }
  // Serial.println(*(p + 1)); // 输出 200 (第二个元素，地址往后挪了一个 int 的位置)
  // Serial.println(*(p + 2)); // 输出 300 (第三个元素)
}

void loop() {
  // put your main code here, to run repeatedly:

}
