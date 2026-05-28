// 两种方法都可以定义pin，但是 #define 对内存的占用更少
const int boardLedPin=13;
#define ledPin=2;

void setup() {
  // 在arduino 通电的时候只会运行一次
  // 通常用来配置引脚模式、启动串口通信等
 
  // 1.pinMode(引脚号, 模式) 写在setup里
  // OUTPUT  &  INPUT   两种模式


  pinMode(13,OUTPUT);

}

void loop() {
  // 核心循环代码：在这里写的代码会像死循环一样，从上到下无限重复运行
  // 硬件的控制逻辑、传感器数据读取都写在这里

  // 1.digitalWrite(引脚号, 状态) & digitalRead(引脚号) & dalay(毫秒数)  写在loop里
  // digitalWrite 有两个mode:  high 5V   |    low 0V

  digitalWrite(13, HIGH);
  delay(5000);
  digitalWrite(13,LOW);
}
