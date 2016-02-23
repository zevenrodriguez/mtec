import random

teamA = ["Davina", "Armin", "Charlie", "Sean", "Shane", "Saranjit", "Robin", "Woodrow"]
teamX = ["James", "Ryan", "Kenny", "Ziaul", "Miles", "Jennifer", "Tamanda"]

teamASize = len(teamA)
teamXSize = len(teamX)

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
        if(teamASize >= 1):
            print(teamA)

        if(teamXSize >= 1):
            print(teamX)
        break
