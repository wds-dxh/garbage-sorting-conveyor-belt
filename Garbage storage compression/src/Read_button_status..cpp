/*
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 22:36:27
 * @LastEditors: wds-dxh wdsnpshy@163.com
 * @LastEditTime: 2024-03-16 11:53:27
 * @FilePath: \Garbage storage compression\src\Read_button_status..cpp
 * @Description: 读取按键状态
 * 微信: 15310638214 
 * 邮箱：wdsnpshy@163.com 
 * Copyright (c) 2024 by ${wds-dxh}, All Rights Reserved. 
 */
#include <Arduino.h>
#include "Read_button_status.h"



/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-16 11:52:46
 * @description: 初始化按键引脚
 * @param {int} button_pin
 * @return {*}
 */
Read_button_status::Read_button_status(int button_pin)
{
    this->button_pin = button_pin;      //初始化按键引脚
    pinMode(button_pin, INPUT);         //设置按键引脚为输入    
}


/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-16 11:54:47
 * @description: 释放按键引脚
 * @return {*}
 */
Read_button_status::~Read_button_status()
{
    //释放按键引脚：无需释放
}







/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-16 11:53:21
 * @description: 返回按键状态
 * @return {*}
 */
bool Read_button_status::read_button_status()
{
    return digitalRead(button_pin);     //读取按键状态
}