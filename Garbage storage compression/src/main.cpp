/*
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-09 13:30:35
 * @LastEditors: wds-dxh wdsnpshy@163.com
 * @LastEditTime: 2024-03-17 16:22:42
 * @FilePath: \Garbage storage compression\src\main.cpp
 * @Description: 垃圾桶压缩控制
 * 微信: 15310638214 
 * 邮箱：wdsnpshy@163.com 
 * Copyright (c) 2024 by ${wds-dxh}, All Rights Reserved. 
 */

#include <Arduino.h>
#include "Stepper_Motor_Control.h"
#include "Read_button_status.h"

Stepper_motor_control stepper_motor(200, 50, A2, A1, A0, 10, 11, 12);       //默认参数初始化
Read_button_status button(A3);
int control_flag = 0;       //控制标志位 
    
void setup() {

    Serial.begin(115200);
    Serial.println("start...");
    stepper_motor.set_motor(100, 16, true);    //设置电机转速，细分，使能引脚状态


}


void loop() {
    int button_status = button.read_button_status();    //读取按键状态
    if (button_status == 0){
        control_flag++;
        if (control_flag % 2 == 0){
            stepper_motor.control_motor(2, -1);     //控制电机旋转
        }
        else{
            stepper_motor.control_motor(2, 1);     //控制电机旋转
        }
    }
    
    delay(100);

}
