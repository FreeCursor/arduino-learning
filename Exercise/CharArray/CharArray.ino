void setup() {
  Serial.begin(9600);

  // 写法 A：手动声明大小（要给 '\0' 留一个格子）
  // "Hello" 有 5 个字母，但数组大小必须至少是 6
  char msg1[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; 

  // 写法 B：最常用、最聪明的写法
  // 用双引号包裹，编译器会自动在末尾加上 '\0'，并自动计算长度为 6
  char msg2[] = "Hello"; 

  Serial.println(msg2); // 正常输出 "Hello"

  // 怎么修改其中的字符？直接通过下标改
  msg2[0] = 'Y'; 
  Serial.println(msg2); // 输出 "Yello"
}

void loop() {
  // put your main code here, to run repeatedly:

}
