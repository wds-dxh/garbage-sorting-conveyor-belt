#ifndef __STEPPER_MOTOR_CONTROL_H
#define __STEPPER_MOTOR_CONTROL_HsetMicrostep

#include "A4988.h"
#include "Arduino.h"
class Stepper_motor_control
{
    private:
        A4988 stepper;
        uint8_t MOTOR_STEPS;
        uint8_t RPM;
        int DIR;
        int STEP;
        int SLEEP;
        uint8_t MS1;
        uint8_t MS2;
        uint8_t MS3;

    public:
        //构造函数
        Stepper_motor_control(uint8_t MOTOR_STEPS,uint8_t RPM, int DIR, int STEP, int SLEEP, uint8_t MS1, uint8_t MS2, uint8_t MS3);
        //设置目标电机转速，细分，使能引脚状态
        void set_motor(int RPM, int microstep, int enable);
        //控制电机旋转
        void control_motor(int circle, int direction);

};



#endif