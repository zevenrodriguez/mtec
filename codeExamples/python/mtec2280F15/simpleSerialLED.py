import serial
ser = serial.Serial(6,9600)
print(ser.name)

while(True):
    command = input("Serial input")
    command = command.strip()
    command = command + "\n"
    command = command.encode()
    print(command)
    ser.write(command)

ser.close()
