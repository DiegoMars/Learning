### User Input ###
# Prints message and asks for an input, can be stored in a variable
name = input("What is your name?: ")
print("Hello " + name)
# Input is automatically converted to a string
# You need to typecast if you want something other than a string
age = int(input("What is your age?: "))
print("You were born in " + str(2023 - age))