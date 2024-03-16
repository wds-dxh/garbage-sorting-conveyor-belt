#ifndef __STEPPER_MOTOR_CONTROL_H
#define __STEPPER_MOTOR_CONTROL_H
#include "A4988.h"
#include <Arduino.h>

class Stepper_motor_control
{
    private:
        A4988 stepper;
    public:
        //构造函数
        Stepper_motor_control(int MOTOR_STEPS,int RPM, int DIR, int STEP, int SLEEP, int MS1 = 10, int MS2 = 11, int MS3 = 12);
        //设置目标电机转速，细分，使能引脚状态
        void set_motor(int RPM, int microstep, int enable);
        //控制电机旋转
        void control_motor(int circle, int direction);

};



#endif