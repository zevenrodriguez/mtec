import sys

listItems = ["Ota", "Tim", "Tojo", "Danny", "Kenneth"]


while(True):

	command = input("Input something: ")

	command = command.strip()

	if(command == "exit"):
		break

	command = command.capitalize()

	#print(type(command))
	print(command)

	count = listItems.count(command)

	print("Number of " + str(command) + " in list: " + str(count))

print ("Thank you for searching")
