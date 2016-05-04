import serial
ser = serial.Serial("COM4",9600)
print(ser.name)

while(True):
    if(ser.inWaiting() > 0):
        s = ser.readline()
        s = s.strip()
        s = s.decode("utf-8")
        if(s == "button1"):
            print(s)
        if(s == "button2"):
            print(s)


ser.close()
