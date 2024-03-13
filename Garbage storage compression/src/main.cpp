#include <Arduino.h>


bool dir_flag = true;//控制步进电机的方向

void setup() {
    
        //设置引脚a3为输入模式，用于控制步进电机的启动
    pinMode(A3, INPUT);  
    //配置引脚a0，a1，a2控制步进电机
    pinMode(A0, OUTPUT);//使能引脚
    pinMode(A1, OUTPUT);//脉冲引脚
    pinMode(A2, OUTPUT);//方向引脚

    //初始化串口，打印信息
    Serial.begin(115200);
    Serial.println("start...");

    

}

//定义使能高低电平
#define ENABLE 0
#define DISABLE 1

void loop() {
    //当按钮按下时，使能引脚输出高电平，使步进电机工作，并且控制方向为正向。旋转角度为360度
    //当按钮再次按下时，使能引脚输出高电平，使步进电机工作，并且控制方向为反向。旋转角度为360度
    //循环往复
    // if(digitalRead(A3) == HIGH){
    //     digitalWrite(A0, HIGH);
    //     digitalWrite(A2, dir_flag);     //控制方向
    //     for(int i = 0; i < 200; i++){
    //         digitalWrite(A1, HIGH);
    //         delayMicroseconds(1000);
    //         digitalWrite(A1, LOW);
    //         delayMicroseconds(1000);
    //     }
    //     digitalWrite(A0, LOW);
        
    // dir_flag = !dir_flag;
    // }

    //步进电机正方向旋转360度，测试
    digitalWrite(A0, ENABLE);
    digitalWrite(A2, HIGH);     //控制方向
    for(int i = 0; i < 200; i++){
        digitalWrite(A1, HIGH);
        delayMicroseconds(500);
        digitalWrite(A1, LOW);
        delayMicroseconds(500);
    }
    digitalWrite(A0, DISABLE);
  
    //步进电机反方向旋转360度，测试
    digitalWrite(A0, ENABLE);
    digitalWrite(A2, LOW);     //控制方向
    for(int i = 0; i < 200; i++){
        digitalWrite(A1, HIGH);
        delayMicroseconds(500);
        digitalWrite(A1, LOW);
        delayMicroseconds(500);
    }
    digitalWrite(A0, DISABLE);
    //循环
    while (1)
    {
        printf("ok\n");    
        delay(1000);    
    }
    
}

