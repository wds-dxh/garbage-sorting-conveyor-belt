'''
Author: wds-dxh wdsnpshy@163.com
Date: 2024-03-17 15:13:44
LastEditors: wds-dxh wdsnpshy@163.com
LastEditTime: 2024-03-17 15:46:48
FilePath: \pc_garbage\predict_esp32cam.py
Description: 
微信: 15310638214 
邮箱：wdsnpshy@163.com 
Copyright (c) 2024 by ${wds-dxh}, All Rights Reserved. 
'''
import time
import cv2
import os
os.environ['YOLO_VERBOSE'] = str(False)#不打印yolov8信息
from ultralytics import YOLO
import socket
import io
from PIL import Image
import numpy as np

from get_need_result import convert_boxes
# 导入串口
import serial

#初始化串口为com6，波特率115200
ser = serial.Serial("COM6", 115200, timeout=0.5)

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
s.bind(("0.0.0.0", 9090))

# 加载YOLOv8模型
model = YOLO('best.pt')


start_time = time.time()
#定义识别到的次数
count1 = 0
count2 = 0
count3 = 0
#保存视屏，设置编码器
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi', fourcc, 20.0, (640, 480))
# 遍历视频帧
save_flag = False
while True:
    data, IP = s.recvfrom(100000)
    bytes_stream = io.BytesIO(data)
    image = Image.open(bytes_stream)
    frame = np.asarray(image)#转换为opencv格式
    frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)  # ESP32采集的是RGB格式，要转换为BGR（opencv的格式）
    if frame is not None:
        # 在该帧上运行YOLOv8推理
        frame = cv2.resize(frame, (640, 480), interpolation=cv2.INTER_LINEAR)
        results = model.predict(frame,conf=0.45,imgsz=(640, 480),max_det=3,save=True)
        # 在帧上可视化结果
        annotated_frame = results[0].plot()
        boxes = results[0].boxes
        xywh, cls = convert_boxes(boxes)
        print(xywh, cls)
        #连续检测到三次才发送数据
        #如果检测到结果不为空
        # if len(cls) == 0:
        #     count1 = 0
        #     count2 = 0
        #     count3 += 1
        #     if count3 == 3:
        #         ser.write(b'135')
        if len(cls) != 0:
            if cls[0] == 0 :
                count1 += 1
                count2 = 0
                if count1 == 3:
                    ser.write(b'170')
            elif cls[0] == 1:
                count2 += 1
                count1 = 0
                if count2 == 3:
                    ser.write(b'110')

        #如果按下s键保存视频
        if cv2.waitKey(1) & 0xFF == ord("s"):
            save_flag = True
            print("保存视频")
        if save_flag:
            out.write(annotated_frame)  
        cv2.imshow("YOLOv8推理", annotated_frame)

        fps = 1.0 / (time.time() - start_time)
        cv2.putText(annotated_frame, f"{fps:.1f} FPS", (0, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
        start_time = time.time()
        # 如果按下'q'则中断循环
        if cv2.waitKey(1) & 0xFF == ord("q"):
            break
    else:
        # 如果视频结束则中断循环
        break


cv2.destroyAllWindows()