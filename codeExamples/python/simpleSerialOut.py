import serial
import time
ser = serial.Serial('COM3', 9600, timeout=0)
var = input("Enter something: ")
ser.write(var.encode())
while 1:
    try:
        msg = ser.readline()
        msg = msg.strip()
        msg = str(msg, encoding="UTF-8")
        if(msg != ""):
            print(msg)
        time.sleep(1)
    except ser.SerialTimeoutException:
        print('Data could not be read')
