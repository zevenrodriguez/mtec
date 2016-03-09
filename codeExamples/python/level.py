import random

class Level(object):
    def __init__(self, levels):
        self.levels = levels

    def levelPrints(self):
        print(self.levels)



setLevels = []

for i in range(10):
    randomLType = []
    for x in range(3):
        randomLType.append(random.randint(0,2))
    #print(randomLType)
    temp = Level(randomLType)
    setLevels.append(temp)

for i in setLevels:
    i.levelPrints()
