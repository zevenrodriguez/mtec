import random

class Level():
    def __init__(self, levelTypes):
        #self.levelTypes refers to a variable inside of the Level Object
        self.levelTypes = levelTypes

    def levelPrints(self):
        print(self.levelTypes)


#List of game levels
setLevels = []
#At this point we have an empty list container

#This creates list of dungeons and adds them to level
for i in range(10):
    #Create an empty container to hold our level types
    randomLType = [] #going to include 3 numbers
    #Generates 3 Random level types
    for x in range(3):
        randomLType.append(random.randint(0,2)) # generates 0,1,2 and add to randomLType
    #Once loop is done, randomLType now contains 3 numbers corresponding to dungeons types
    #print(randomLType)
    #every time main loop runs we create a new object
    #giving information from randomLtype to a Level object
    temp = Level(randomLType)
    #temp becomes a Level object
    #add temp to setLevels list
    setLevels.append(temp)

#print(setLevels)
print("Original Levels...")

#levelPrints is a function of the Level object
#Here i is looping through objects
for levelObject in setLevels:
    #i = current Level object
    levelObject.levelPrints()

print("Setting Boss Levels...")

#len is length, size of list, size of setLevels is 10
#i is looping through randge numbers
for number in range(len(setLevels)):
    #i = index
    if (number == 5 or number == 9):
        #setting a boss condition
        #setLevels[i].levelTypes refers to the variable levelTypes inside of the object
        setLevels[number].levelTypes = [3,3,3]
    setLevels[number].levelPrints()
