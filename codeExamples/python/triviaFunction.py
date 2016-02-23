import sys

def capital(cap):
    if(cap == "2"):
        print("You are correct!")
    else:
        print("Wrong Answer!")



print("What is the capital of New York? \n 1. New York City \n 2. Albany \n 3. Buffalo \n 4. Kingston")

answer = input("Answer: ")

capital(answer)
