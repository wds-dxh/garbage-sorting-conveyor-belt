/*
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 10:32:21
 * @LastEditors: wds-dxh wdsnpshy@163.com
 * @LastEditTime: 2024-03-17 12:39:29
 * @FilePath: \Steering gear control\src\Steering_gear_control.cpp
 * @Description: 舵机驱动控制
 * 微信: 15310638214 
 * 邮箱：wdsnpshy@163.com 
 */

#include"Steering_gear_control.h"


/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-17 12:31:36
 * @description: 舵机引脚初始化
 * @param {uint8_t} SERVO_PIN
 * @return {*}
 */
Steering_gear_control::Steering_gear_control(uint8_t SERVO_PIN)
{
    this->ServoPin = SERVO_PIN;
}



/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-17 12:33:43
 * @description: 初始化舵机参数
 * @param {int} freq
 * @param {int} channel
 * @param {int} resolution
 * @param {float} deadZone
 * @param {float} max
 * @param {uint16_t} angleRange
 * @return {*}
 */
void Steering_gear_control::servoConfig(int freq = 50, int channel = 8, int resolution = 8, float deadZone = 6.4, float max = 32, uint16_t angleRange = 270)
{
    servoConf.freq = freq;
    servoConf.channel = channel;
    servoConf.resolution = resolution;
    servoConf.deadZone = deadZone;
    servoConf.max = max;
    servoConf.angleRange = angleRange;
    ledcSetup(channel, freq, resolution);
    ledcAttachPin(ServoPin, channel);
}


/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-17 12:40:04
 * @description: 控制舵机旋转
 * @param {uint16_t} angle
 * @return {*}
 */
void Steering_gear_control::singleServoControl(uint16_t angle)
{
    ledcWrite(servoConf.channel, calculatePWM(angle));
}


/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-17 12:51:40
 * @description: 计算PWM值
 * @param {uint16_t} angle
 * @return {*}
 */
int Steering_gear_control::calculatePWM(uint16_t angle)
{   
    if (angle<0)
    {
        angle = 0;
    }
    else if (angle>servoConf.angleRange)
    {
        angle = servoConf.angleRange;
    }
    int pwm = (int)(((servoConf.max - servoConf.deadZone) / servoConf.angleRange) * angle + servoConf.deadZone);
    return pwm;
    
}