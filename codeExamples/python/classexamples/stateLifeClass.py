# levels are forest, street, beach
#fight, run, defend (randomize)
#poison, life (randomize)
#combination

import random

state = 0
lifeBar = 3
score  = 0

def checkLife():
    global lifeBar
    global state
    print("Your current life is: " + str(lifeBar))
    if(lifeBar == 0):
        state = 5

def checkScore():
    global score
    global state
    print("Your current score is: " +str(score))
    if(score == 3):
        state = 4

def battle(battleMove):
    print("You are " + battleMove + "ing")
    battleOutcome = outcome()
    return battleOutcome

def outcome():
    global lifeBar
    global score

    consequence = random.randint(0,1)

    if(consequence == 0):
        print("You are hurt")
        lifeBar = lifeBar - 1
        return False

    if(consequence == 1):
        print("You gained a point")
        score = score + 1
        return True
def gameOver():
    global lifeBar
    global score
    restart = input("Would you like to start over or or exit ")
    if(restart == "start over"):
        lifeBar = 3
        score = 0
        return False

    if(restart == "exit"):
        return True



while(True):
    #game is going to happen
    checkLife()
    checkScore()

    if(state == 0):
        #crossroad
        print("You are at a crossroad. Which way will you go?")

        command = input("Towards forest or street or beach: ")

        if(command == "forest"):
            print("You are going forest")
            state = 1
        elif(command == "street"):
            print("You are going street")
            state = 2
        elif(command == "beach"):
            print("You are going beach")
            state = 3
        else:
            print("Wrong input")
            state = 0


    if(state == 1):
        #forest
        print("You are in the forest. A giant troll appears. Do you want to fight, run, or defend?")
        command = input("fight, run, or defend ")
        if(command == "fight" or command == "run" or command == "defend"):
            #do something
            result = battle(command)
            if(result == True):
                print("You beat the troll")
                state = 0
            else:
                state = 1
        else:
            print("Wrong input")
            state = 1



    if(state == 2):
        #street
        print("You are on the street. There is a mysterious package on the floor.")
        command = input(" Do you want to pickup or keep walking? ")
        if(command == "pickup"):
        #run outcome
            package = outcome()
            if(package == True):
                print("You found an elixer")
                state = 0
            else:
                print("You found poison")
                state = 0

        elif(command == "keep walking"):
            state = 0
        else:
            print("Wrong input")
            state = 2


    if(state == 3):
        #beach
        print("You are on the beach.")
        mode = random.randint(0,1)
        if(mode == 0):
            #fight
            print("A giant crab appears.")
            command = input("Do you want to fight, run, or defend? ")
            if(command == "fight" or command == "run" or command == "defend"):
                result = battle(command)
                if(result == True):
                    print("You beat the crab")
                    state = 0
                else:
                    state = 0
            else:
                print("Wrong input")
                state = 0

        if(mode == 1):
            #item
            print("There is a mysterious package on the floor.")
            command = input(" Do you want to pickup or keep walking? ")
            if(command == "pickup"):
                package = outcome()
                if(package == True):
                    print("You found an elixer")
                    state = 0
                else:
                    print("You found poison")
                    state = 0
            elif(command == "keep walking"):
                state = 0
            else:
                print("Wrong input")
                state = 3

    if(state == 4):
        #win
        print("You have reached your goal!")
        over = gameOver()
        if(over == True):
            break
        else:
            state = 0

    if(state == 5):
        #lose
        print("You are dead!")
        over = gameOver()
        if(over == True):
            break
        else:
            state = 0
