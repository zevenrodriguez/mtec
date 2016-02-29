state = 0


while(True):
    if(state == 0):
        print("You are in the forest. Which way will you go?")
        command = input("Left or Right")
        if(command == "left"):
            print("you are going left")
            state = 1
        elif(command == "right"):
            print("you are going right")
            state = 2
        else:
            print("Wrong input")
            state = 0
    if(state == 1):
        print("You are in the street. Which way will you go?")
        command = input("Left or Right")
        if(command == "left"):
            print("you are going left")
            state = 0
        elif(command == "right"):
            print("you are going right")
            state = 2
        else:
            print("Wrong input")
            state = 1

    if(state == 2):
        print("You have reached your goal")
        break


print("Thank you for playing")
