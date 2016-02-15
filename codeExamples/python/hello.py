var  = 1

var1 = "hello"

var2 = "1"

var3 = 2

var4 = True

var5 = 2.0


#print("Hello World!")

#print(var)

#print(var2)

#print(var1)

# 1 + 2 = 3
print(var + var3)
print(var - var3)
print(var * var3)
print(var / var3)

print("HELLO")
print("world")


print(type(var))
print(type(var1))
print(type(var4))
print(type(var5))

# adding integer and float
# 1 + 2.0
print(var + var5)
# adding integer and string
# 1 + "1"
# this will give you an error
#print(var + var2)

#typecasting
guess = "12345"
print(type(guess))
#grab the word guess and converts into integer
troll = int(guess)
print(troll)
print(type(troll))
print("You lose!!!!! The answer was:")
print(troll + 1)

# adding strings
hello = "Hello"
world = "World"
spacer = " "

print(hello + spacer +world)
#render the same as above
print(hello + " " + world)


guess2 = 1234214321
# no issue printing
print(guess2)
# issue comes when adding a string, You need to typecast the integer
print("Your guess was: " + str(guess2))
