// 声明一个共享变量。注意：中断函数里要修改的变量，必须加上 volatile 关键字
// volatile 关键字，禁用自动代码优化(不会缓存数据至寄存器register)
volatile bool triggerAction=false;
const int triger=2;
// **最优使用条件
// 1.这个变量是一个全局变量
// 2.这个变量既在主程序（setup / loop）里被读取或修改，又在中断服务函数（ISR）里被读取或修改


void setup() {
  Serial.begin(9600);
  // 设置2号引脚为输入(带上拉电阻)
  pinMode(triger,INPUT_PULLUP);
  // digitalPinToInterrupt(2) 把硬件引脚转成中断
  // myISR 中断发生时要去执行的函数
  // FALLING 表示中断触发模式是电平降低瞬间
  attachInterrupt(digitalPinToInterrupt(2),myISR,FALLING);
}

void loop() {
  Serial.println("Main loop is running");
  delay(10000);
  if(triggerAction){
    Serial.println("--> Interrupt detected");
  }
}
void myISR(){
  triggerAction=true;
}
