import sys

def capital(cap):
    if(cap == "2"):
        return(True)
    else:
        return(False)

print("What is the capital of New York? \n 1. New York City \n 2. Albany \n 3. Buffalo \n 4. Kingston")

answer = input("Answer: ")

response = capital(answer)

print(response)

if(response == True):
    print("You are Correct!")
else:
    print("Get an Atlas")
