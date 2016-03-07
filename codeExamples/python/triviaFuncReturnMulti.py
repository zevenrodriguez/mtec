import sys

def capital(cap):
    if(cap == "2"):
        return(1)
    elif(cap == "1" or cap == "3" or cap == "4"):
        return(2)
    else:
        return(0)

print("What is the capital of New York? \n 1. New York City \n 2. Albany \n 3. Buffalo \n 4. Kingston")

answer = input("Answer: ")

response = capital(answer)

print("The reponse is " + str(response))

if(response == 1):
    print("You are Correct!")
elif(response == 2):
    print("Get an Atlas")
elif(response == 0):
    print( answer + " is not a valid response! Choose 1,2,3,4.")
