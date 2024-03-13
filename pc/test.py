import cv2
import numpy as np
import socket

# 创建一个Socket对象
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('127.0.0.1', 9999)  # 将这里的IP和端口设置为C++服务端的IP和端口
client_socket.connect(server_address)

while True:
    try:
        # 接收数据
        data = client_socket.recv(480 * 640)
        if not data:
            break

        # 将接收到的数据转换为图像
        img_array = np.frombuffer(data, dtype=np.uint8)
        img = cv2.imdecode(img_array, cv2.IMREAD_COLOR)

        # 在窗口中显示图像
        cv2.imshow('Received Video', img)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    except Exception as e:
        print(f'错误：{e}')
        break

# 关闭窗口和Socket连接
cv2.destroyAllWindows()
client_socket.close()
