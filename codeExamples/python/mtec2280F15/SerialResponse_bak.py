import serial
import time
ser = serial.Serial(6,9600, timeout=1)
breaking = True
arduinoCur = ""
print(ser.name)

while(breaking):
    print("waiting...")
    aStart = ser.readline().strip()
    aStart = aStart.decode()
    print(aStart)
    if(aStart == 'A'):
        print("done")
        ser.write('a'.encode());
        print(ser.inWaiting())
        if(ser.inWaiting()>0):
            print("greater")
            while(ser.inWaiting()> 0):
                 print("clearing")
                 print(ser.read())
        print(ser.inWaiting())
        breaking = False;

while(True):
    print(ser.inWaiting())
    if(ser.inWaiting()>0):
        print("greater")
        while(ser.inWaiting()> 0):
             print("clearing")
             print(ser.read())
    # while(ser.inWaiting()> 0):
    #     print("clearing")
    #     print(ser.read())
    print(ser.inWaiting())
    print("connected")
    command = input("Serial input: ")
    command = command.strip()
    command = command + "\n"
    command = command.encode()
    print(command)
    ser.write(command)
    time.sleep(.1)
    print("Command sent")
    print("waiting after command: " + str(ser.inWaiting()))
    if(ser.inWaiting()>0):
        print("greater")
        while(ser.inWaiting()> 0):
             print("clearing")
             print(ser.read())

    arduinoCur = ser.readline().strip()
    arduinoCur = arduinoCur.decode()

    print("current arduino status: " + arduinoCur)
    if(arduinoCur == 'h'):
        print("arduino high")
    elif(arduinoCur == 'l'):
        print("arduino low")




ser.close()
