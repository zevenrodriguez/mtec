import serial
ser = serial.Serial("COM3",9600)
print(ser.name)

while(True):
    s = ser.readline()
    s = s.strip()
    s = s.decode("utf-8")
    if(s == "hello"):
        print(s)

ser.close()
