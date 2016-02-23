import sys

num  = sys.argv[1]
sign  = sys.argv[2]
num2  = sys.argv[3]
calc = 0

if (sign == "+"):
    calc = int(num) + int(num2)

if(sign == "*"):
    calc = int(num) * int(num2)


print(calc)
