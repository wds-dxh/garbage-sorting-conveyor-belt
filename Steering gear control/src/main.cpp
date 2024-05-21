/*
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 10:30:03
 * @LastEditors: wds-dxh wdsnpshy@163.com
 * @LastEditTime: 2024-03-17 13:46:15
 * @FilePath: \Steering gear control\src\main.cpp
 * @Description: 
 * 微信: 15310638214 
 * 邮箱：wdsnpshy@163.com 
 */
#include <Arduino.h>
#include "Steering_gear_control.h"


Steering_gear_control steering_gear_control(13);  //声明一个舵机对象，引脚为9
void setup() {

    steering_gear_control.servoConfig(50, 8, 8, 6.4, 32, 270); //初始化舵机参数
    steering_gear_control.singleServoControl(135);
    Serial.begin(115200);
    Serial.println("init success");
    
}


void loop() {
    //根据收到的串口角度来调节舵机角度
    if(Serial.available() > 0 )
    {
        uint16_t angle = Serial.parseInt(); //读取串口数据
        if (angle != 0){

        if (angle > 170)
         {
              angle = 170;
            }
        if (angle < 110)
        {
            angle = 110;
        }
        steering_gear_control.singleServoControl(angle);
        Serial.println(angle);
        delay(100);
        //一次命令完成
        Serial.println("ok");
    
        }
        
       
    }
       
}


