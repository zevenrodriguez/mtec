import sys

while (True) :  # This constructs an infinite loop
   command = raw_input("Enter a command: ")
   if command == "exit":
       break
   else:
       print(command)
