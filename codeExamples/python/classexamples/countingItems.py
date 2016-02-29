import sys

listItems = ["Cars", "Video GaMes", "trees", "BlackJack", "blackjack"]

listCounter = 0

find = input("Search for Something: ")

find = find.lower()

for f in listItems:
    print("Items in list: " + f)
    f = f.lower()
    print("Items after lower case: " + f)
    if(f == find):
        listCounter = listCounter + 1

print("Number of items in list: " + str(listCounter))
# countItems = listItems.count(find)
#
# print(countItems)
