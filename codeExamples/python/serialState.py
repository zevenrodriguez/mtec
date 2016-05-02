import serial
ser = serial.Serial("ENTER COMPORT HERE",9600)

state = 0


while(True):
    if(state == 0):
        print("You are in the forest. Which way will you go?")
        command = input("Left or Right")
        if(command == "left"):
            print("you are going left")
            state = 1
            message = "1" + "\n"
            message = message.encode()
            ser.write(message)
        elif(command == "right"):
            print("you are going right")
            state = 2
            message = "2" + "\n"
            message = message.encode()
            ser.write(message)
        else:
            print("Wrong input")
            state = 0
    if(state == 1):
        print("You are in the street. Which way will you go?")
        command = input("Left or Right")
        if(command == "left"):
            print("you are going left")
            state = 0
            message = "0" + "\n"
            message = message.encode()
            ser.write(message)
        elif(command == "right"):
            print("you are going right")
            state = 2
            message = "2" + "\n"
            message = message.encode()
            ser.write(message)
        else:
            print("Wrong input")
            state = 1
            message = "1" + "\n"
            message = message.encode()
            ser.write(message)

    if(state == 2):
        print("You have reached your goal")
        message = "2" + "\n"
        message = message.encode()
        ser.write(message)
        break


print("Thank you for playing")
