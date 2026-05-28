// 有限状态机
// 1.enum枚举
boolean currentState=true;

// 创建了一个新的数据类型
// 它只能在这三个代号里取值
enum StageState{
  READY,
  FIRE,
  COOLDOWN
};

StageState mySystemState=READY;  // 初始状态设为 READY
unsigned long stateStartTime=0;
const int buttonPin=2;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop() {
  unsigned long currentTime=millis(); //引入前面学到的非阻塞时间
  switch (mySystemState) {
    case READY:
      if(digitalRead(buttonPin)==LOW){  // 因为上面有个上拉电阻，所以开关未触发前都是高电平，触发了就是低电平
        Serial.println("System triggered! Entering stage 1...");
        // 满足条件开始运行
        mySystemState=FIRE;
        stateStartTime=currentTime;
      }
      break;

    case FIRE:
      if(currentTime-stateStartTime < 500){
        Serial.println("Action completed! Syetem entering cooling period...");
        mySystemState=COOLDOWN;
        stateStartTime=currentTime;
      }
      break;

      case COOLDOWN:
        if(currentTime-stateStartTime>=3000){
            Serial.println("Cool down finished. System Ready again!");
            mySystemState = READY; // 冷却结束，回到最初状态
        }
        break;
  }
 
}
