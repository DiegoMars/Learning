### String Methods ###
name = "diego"

# returns length of string
print(len(name))
# finds index of character, or returns -1
print(name.find("D"))
# looks starting from the end
print(name.rfind("d"))
# capitalizes first letter
print(name.capitalize())
#capitalizes first letter of each word
print(name.title())
# caps or lowers all characters
print(name.upper())
print(name.lower())
# checks if it's a number
print(name.isdigit())
# checks if it contains only letters
print(name.isalpha())
# counts number of specified character in string, add 2 more values to search between the first index and before the last index
print(name.count("e"))
# replace chracter for another, add another value to do it that value number of times
print(name.replace("o","d"))
# print multiple times
print(name*3)