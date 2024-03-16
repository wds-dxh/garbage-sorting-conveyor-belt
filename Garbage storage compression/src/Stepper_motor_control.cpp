/*
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 21:04:27
 * @LastEditors: wds-dxh wdsnpshy@163.com
 * @LastEditTime: 2024-03-16 13:12:05
 * @FilePath: \Garbage storage compression\src\Stepper_motor_control.cpp
 * @Description: 
 * 微信: 15310638214 
 * 邮箱：wdsnpshy@163.com 
 * Copyright (c) 2024 by ${wds-dxh}, All Rights Reserved. 
 */




#include "Stepper_Motor_Control.h"
/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 21:46:48
 * @description: a4988控制步进电机初始化
 * @param {int} MOTOR_STEPS 步进电机步数
 * @param {int} RPM         电机转速
 * @param {int} DIR         电机方向
 * @param {int} STEP        电机脉冲    
 * @param {int} SLEEP       电机使能
 * @param {int} MS1         电机细分
 * @param {int} MS2         电机细分
 * @param {int} MS3         电机细分
 * @return {*}
 */
Stepper_motor_control :: Stepper_motor_control(uint8_t MOTOR_STEPS,uint8_t RPM, int DIR, int STEP, int SLEEP, uint8_t MS1, uint8_t MS2, uint8_t MS3)
    :stepper(MOTOR_STEPS, DIR, STEP, SLEEP, MS1, MS2, MS3){
    //初始化步进电机
    this->MOTOR_STEPS = MOTOR_STEPS;
    this->RPM = RPM;
    this->DIR = DIR;
    this->STEP = STEP;
    this->SLEEP = SLEEP;
    this->MS1 = MS1;
    this->MS2 = MS2;
    this->MS3 = MS3;

}


/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 21:57:58
 * @description: 设置电机转速，细分，使能引脚状态
 * @param {int} RPM         电机转速
 * @param {int} microstep   电机细分
 * @param {int} enable      电机使能
 * @return {*}
 */
void Stepper_motor_control :: set_motor(int RPM, int microstep, int enable){

    stepper.begin(RPM);
    stepper.setMicrostep(microstep);
    stepper.setEnableActiveState(LOW);
    if (enable == true){
        stepper.enable();
    }
    else{
        stepper.disable();
    }                 
}

/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 22:02:47
 * @description: 控制步进电机旋转
 * @param {int} circle
 * @param {int} direction
 * @return {*}
 */
void Stepper_motor_control :: control_motor(int circle, int direction){

    //电机旋转circle圈，方向为direction
    stepper.rotate(circle * 360 * direction);
    
}