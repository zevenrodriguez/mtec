import sys, random

randNum = random.randint(0,100)

while(True):
    #print('...Running')
    print("The answer is : " + str(randNum))
    guess = input("Pick a number from 0-99? Type exit to finish game")

    print("You have guessed" + str(guess))

    if(guess == "exit"):
        break
    elif(guess == str(randNum)):
        print("you won. new number generated")
        randNum = random.randint(0,100)

    else:
        print("you lost")


print("Thank you for playing!")
