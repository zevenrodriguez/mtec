yArray = [1,"hello", 'a', 1.234, 1]

print(yArray)

#Counts the amount of a certain parameter in an array
print(yArray.count(1))

#Orders the Array
yArray.sort()
print(yArray)

#Sorts the array in reverse
yArray.reverse()
print(yArray)

#Add to end of array
yArray.append("goodbye")
print(yArray)

#Add in a position
yArray.insert(2,"inserted")
print(yArray)

#Remove last item and returns it
print(yArray.pop())

#Removes element based on parameter
yArray.remove("hello")
print(yArray)
