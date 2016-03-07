import sys

def printSomething():
    print("Print something")

#message will only be referenced with in this funtion
def printSomethingElse(message):
    print(message)

def printMultiThings(message1 , message2):
    print(message1 + " " + message2)



printSomething()
printSomethingElse("hello")
printSomethingElse("goodbye")
printMultiThings("hello", "world")
