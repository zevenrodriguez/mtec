import sys

number = sys.argv[1]
sign = sys.argv[2]
number2 = sys.argv[3]
calc = 0

print(type(number))
print(type(sign))
print(type(number2))

if(sign == '+'):
    calc = int(number) + int(number2)

print(number + '+' + number2)
print(calc)
