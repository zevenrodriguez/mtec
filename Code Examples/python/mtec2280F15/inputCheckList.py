import sys

teamA = ["Ota", "Tim", "Tojo", "Danny", "Kenneth", "Ellington", "Maxinme", "Reno", "Ryan", "Brian", "Dimple", "Edwin", "Tucker", "Carlos", "Fanzhong"]

while (True) :  # This constructs an infinite loop
   command = input("Enter a command: ")
   if command == "exit":
       break
   else:
       num = teamA.count(command)
       print("Number of " + str(command) + " in list: " + str(num))
