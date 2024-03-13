import socket
import cv2
import io
from PIL import Image
import numpy as np

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
s.bind(("0.0.0.0", 9090))

# Define video writer
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('move.avi', fourcc, 20.0, (480, 320))  # Adjust the parameters as needed

while True:
    data, IP = s.recvfrom(100000)
    bytes_stream = io.BytesIO(data)
    image = Image.open(bytes_stream)
    img = np.asarray(image)
    #打印视频大小
    print(img.shape)
    img = cv2.cvtColor(img, cv2.COLOR_RGB2BGR)

    # Display the image
    cv2.imshow("ESP32 Capture Image", img)

    # Write the frame to the video file
    out.write(img)

    if cv2.waitKey(1) == ord("q"):
        break

# Release the video writer and close the window
out.release()
cv2.destroyAllWindows()
s.close()
