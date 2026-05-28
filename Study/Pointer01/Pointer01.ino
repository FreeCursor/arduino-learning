int sum = 255;      // 创建一个变量，值是 255
int *ptrSum;       // 声明一个指针变量，* 表示“我是指针”

void setup() {
  Serial.begin(9600);
  
  ptrSum = &sum;   // 把 sum 的地址（门牌号）赋给指针 ptrSum
  
  Serial.print("sum 的值: ");
  Serial.println(sum);       // 输出 255
  
  Serial.print("sum 的地址: ");
  Serial.println((unsigned long)ptrSum, HEX); // 输出类似 90000000 的十六进制地址
  
  Serial.print("通过指针访问 sum 的值: ");
  Serial.println(*ptrSum);   // *ptrSum 意思是：去 ptrSum 存的地址看一眼，输出 255
}

void loop() {}
