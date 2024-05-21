/*
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 10:32:11
 * @LastEditors: wds-dxh wdsnpshy@163.com
 * @LastEditTime: 2024-03-17 12:32:52
 * @FilePath: \Steering gear control\include\Steering_gear_control.h
 * @Description: 舵机控制类
 * 微信: 15310638214 
 * 邮箱：wdsnpshy@163.com 
 * Copyright (c) 2024 by ${wds-dxh}, All Rights Reserved. 
 */
#ifndef __STEERING_GEAR_CONTROL_H
#define __STEERING_GEAR_CONTROL_H 
#include <Arduino.h>
//定义结构体来存储舵机参数
typedef struct
{
    int freq;      // 频率(20ms周期)
    int channel;    // 通道(高速通道（0 ~ 7）由80MHz时钟驱动，低速通道（8 ~ 15）由 1MHz 时钟驱动。)
    int resolution; // 分辨率
    float deadZone;//对应0.5ms（0.5ms/(20ms/256）) 舵机转动角度与占空比的关系：(角度/90+0.5)*1023/20
    float max;//对应2.5ms
    uint16_t angleRange;//舵机角度范围
}ServoConf;




class Steering_gear_control
{      
    private:
        ServoConf servoConf; //舵机参数
        //定义舵机引脚
        int ServoPin;
                                   
    public:
        //构造函数
        Steering_gear_control(uint8_t SERVO_PIN);
        //舵机配置
        void servoConfig(int freq, int channel, int resolution, float deadZone, float max, uint16_t angleRange);
        //舵机控制
        void singleServoControl(uint16_t angle);
        int calculatePWM(uint16_t angle); //计算PWM值
};

#endif // __STEERING_GEAR_CONTROL_H