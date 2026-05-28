#include "MyBlinker.h" //  注意：当前目录下的头文件，必须用【双引号 ""】，不能用尖括号 <>

MyBlinker statusLed(9, 1500); // 实例化一个对象（注意：C++ 实例化对象不需要像 Java 那样写 new！）

void setup() {
  statusLed.begin();
}

void loop() {
  statusLed.update(); // 完美的非阻塞多任务刷新
}
