---
title: 智能小车-电子器件控制
categories: CAT
tags: TAG
date: 2021-07-19
---

## 舵机

- 转角范围: $0-180$, 也有其他的范围
- 角度控制：调节PWM信号的占空比。标准的控制信号是在周期为20ms的PWM波上，通过1ms-2ms脉宽控制转角范围。
- 接线：棕-GND，红-+5V，橙-信号线

Servo库：提供舵机控制的封装函数

```c++
#include <Servo.h>

Servo myservo;  // 定义Servo对象来控制
int pos = 0;    // 角度存储变量

void setup() {
  myservo.attach(9);  // 控制线连接数字9
}

void loop() {
  for (pos = 0; pos <= 180; pos ++) { // 0°到180°
    // in steps of 1 degree
    myservo.write(pos);              // 舵机角度写入
    delay(5);                       // 等待转动到指定角度
  }
  for (pos = 180; pos >= 0; pos --) { // 从180°到0°
    myservo.write(pos);              // 舵机角度写入
    delay(5);                       // 等待转动到指定角度
  }
}
```

## 电调

好盈1060 60A 有刷电调

控制：通过PWM占空比来设置。控制脉宽在1ms-2ms，分别对应油门最小和最大。有些电调支持倒车，则以1.5ms为界,[1ms,1.5ms)是倒车，(1.5ms,2ms]前进。

油门校准：油门校准网上说法不一。常见说法是在电调上电时先把油门调到100%,持续2s，再把油门调至最低持续1s。但是根据随附说明书，对于该双向电调，直接把油门调至中位点，持续2s即可校准。

校准过程：arduino上电，油门信号输出脉宽1.5ms的信号，同时电调上电，听到两声“哔-哔”(表示2s电池)，同时红灯闪烁。等待1s左右，听到一声“哔”，红灯常亮，校准自检完毕，可以正常使用。

```c++
int PWMPin = 9; //2~13
int PWMValue = 0; //0~1000

String comStr = "";
int comInt=0;


void PWM(int PWMPin, int PWMValue){  // 模拟PWM；频率50Hz
  PWMValue += 1000;
  digitalWrite(PWMPin, HIGH);
  delayMicroseconds(PWMValue);
  digitalWrite(PWMPin, LOW);
  delayMicroseconds(20000 - PWMValue);
}



void setup(){

  pinMode(PWMPin, OUTPUT);

  Serial.begin(9600); // start serial port
  while(Serial.read()>=0){} // clear serial port's buffer
  Serial.println("Arduino on.");
  
  delay(2000);
  
  Serial.println("start controller ...");

  for(int i = 0; i <= 220;i++){  // 中间位置自检
    PWM(PWMPin, 500);
  }

  
  Serial.println("complete.");

}



void loop(){

  
  if (Serial.available() > 0){
    // listen the Serial port, run the code when something catched..
    delay(10);
    comStr = Serial.readString(); // read out the string
    comInt = comStr.toInt(); // convert the string to integer
    comInt = constrain(comInt, 0, 600); // limit the integer between to 1000 and 2000
    
    for(int i=0;i<=30;i++){
      PWM(PWMPin, comInt);  // 设置油门大小0~1000
    }
    
    Serial.print("get command:");
    Serial.println(comInt); // show the integer number on Serial Monitor
  }
}

/**
myServo.writeMicroseconds(1000); 也有用servo库直接控制
**/
```