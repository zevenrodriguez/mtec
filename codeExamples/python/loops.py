
# Loop through a range of numbers from 0 - 4
for i in range(0,5):
    print(i)

yArray = [1,"hello", 'a', 1.234, 1]

#Print out yArray
for i in yArray:
    print(i)

print("yArray Length: " + str(len(yArray)))

#Using the range funtion to itterate through array
for i in range(0,len(yArray)):
    print(str(i) + " : " +str(yArray[i]))


items = ["dog", "cat", "mouse", "chimp"]

for item in items:
    print(item)

for i in range(0,len(items)):
    print(items[i])

randomItems = ["puppy", 45, False]

for z in randomItems:
    print(type(z))
