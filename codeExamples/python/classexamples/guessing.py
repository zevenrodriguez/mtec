import sys
import random

answer = random.randint(0,100)

# python guessing.py
#length sys.argv = 1

# python guessing.py answer
#length sys.argv = 2

#length of the array of sys.argv
print(len(sys.argv))

if(len(sys.argv) > 1):
    if (sys.argv[1] == "answer"):
        print(answer)

guess = input("What is your guess 0 - 99?")

if(answer == int(guess)):
    print("You won")
else:
    print("you lost")

#print(type(guess))
