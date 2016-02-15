import sys

#filename = sys.argv[0]
guess = sys.argv[1]
answer = 200

#print(filename)

#I want to check the type
#print(type(guess))
#convert string to integer
intGuess = int(guess)

#if statement is equal is true => you won
if(intGuess == answer):
	print("You won!")

#if statment is not equal is true => you lose
if(intGuess != answer):
	print("LOSER!!!!!")
