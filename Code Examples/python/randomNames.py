import random

teamA = ["Ota", "Tim", "Tojo", "Danny", "Kenneth", "Ellington", "Maxinme"]
teamX = ["Reno", "Ryan", "Brian", "Dimple", "Edwin", "Tucker", "Carlos", "Fanzhong"]

teamASize = len(teamA)
teamXSize = len(teamX)

if(teamASize > teamXSize):
    currentA = random.randrange(teamASize)
    print(teamA[currentA])
    print()
    teamA.pop(currentA)

if(teamXSize > teamASize):
    currentX = random.randrange(teamXSize)
    print(teamX[currentX])
    print()
    teamX.pop(currentX)

while(teamASize >= 0 or teamXSize >= 0):
    teamASize = len(teamA)
    teamXSize = len(teamX)
    #print("TeamA " + str(teamASize))
    #print("TeamX " + str(teamXSize))
    if (teamASize > 0 and teamXSize > 0):
        currentA = random.randrange(teamASize)
        currentX = random.randrange(teamXSize)
        print(teamA[currentA] + " " + teamX[currentX])
        print()
        teamA.pop(currentA)
        teamX.pop(currentX)
    else:
        break
