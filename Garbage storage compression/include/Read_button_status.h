/*
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-13 22:36:23
 * @LastEditors: wds-dxh wdsnpshy@163.com
 * @LastEditTime: 2024-03-16 11:50:47
 * @FilePath: \Garbage storage compression\include\Read_button_status.h
 * @Description: 读取按键状态
 * 微信: 15310638214 
 * 邮箱：wdsnpshy@163.com 
 * Copyright (c) 2024 by ${wds-dxh}, All Rights Reserved. 
 */
#ifndef __READ_BUTTON_STATUS_H
#define __READ_BUTTON_STATUS_H


/**
 * @Author: wds-dxh wdsnpshy@163.com
 * @Date: 2024-03-16 11:50:24
 * @description: 读取按键状态类
 * @return {*}
 */
class Read_button_status
{
    private:
        int button_pin;
    public:
        Read_button_status(int button_pin = A3);
        ~Read_button_status();
        bool read_button_status();
};

#endif