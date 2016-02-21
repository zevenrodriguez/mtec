yArray = [1,"hello", 'a', 1.234, 1]
xArray = [1,3,4,2,5]


print(yArray)

print(type(yArray))
print(type(xArray))
#Counts the amount of a certain parameter in an array
print(yArray.count(1))

#Orders the Array
xArray.sort()
print(xArray)

#Sorts the array in reverse
xArray.reverse()
print(xArray)

#Add to end of array
yArray.append("goodbye")
print(yArray)

#Add in a position
yArray.insert(6,"inserted")
print(yArray)

#Remove last item and returns it
print(yArray.pop())

#Removes element based on parameter
yArray.remove("hello")
print(yArray)
