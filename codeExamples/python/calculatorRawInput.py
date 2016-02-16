import sys

number = raw_input("Enter the first number: ")
sign = raw_input("Enter sign: ")
number2 = raw_input("Enter the first number: ")
calc = 0

print(type(number))
print(type(sign))
print(type(number2))

if(sign == '+'):
    calc = int(number) + int(number2)

print(number + '+' + number2)
print(calc)
