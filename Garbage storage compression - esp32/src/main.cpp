#include <Arduino.h>


bool dir_flag = true;//控制步进电机的方向

//定义使能引脚，脉冲引脚，方向引脚
#define ENA 15
#define PUL 2
#define DIR 4
void setup() {
    
    

    pinMode(ENA, OUTPUT);//使能引脚
    pinMode(PUL, OUTPUT);//脉冲引脚
    pinMode(DIR, OUTPUT);//方向引脚

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
    digitalWrite(ENA, ENABLE);
    digitalWrite(DIR, HIGH);     //控制方向
    for(int i = 0; i < 200; i++){
        digitalWrite(PUL, HIGH);
        delayMicroseconds(500);
        digitalWrite(PUL, LOW);
        delayMicroseconds(500);
    }
    digitalWrite(ENA, DISABLE);
  
    //步进电机反方向旋转360度，测试
    digitalWrite(ENA, ENABLE);
    digitalWrite(DIR, LOW);     //控制方向
    for(int i = 0; i < 200; i++){
        digitalWrite(PUL, HIGH);
        delayMicroseconds(500);
        digitalWrite(PUL, LOW);
        delayMicroseconds(500);
    }
    digitalWrite(ENA, DISABLE);
    //循环
    while (1)
    {
        printf("ok\n");    
        delay(1000);    
    }
    
}

