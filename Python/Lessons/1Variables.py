### Variables ###
# Strings: use quotes or double quotes in a variable in order to add comments
name = 'Diego'
print(name)

# You can combine values in variables, but they have to be the same type
firstName = 'Diego'
lastName = 'Martinez'
name = firstName + ' ' + lastName
print(name)

# Use "type" in order to output what type of variable a variable is
print(type(name))

# int: whole numbers
age = 18
# age = age + 1 or
age += 1
print(age)
print(type(age))

# float: a decimal
height = 5.10
print(height)
print(type(height))

# boolean: only stores true or false
human = False
print(human)
print(type(human))

### Multiple Assignment ###
# Assign multiple variables at the same time
name , age , male = 'Diego', 18, True
print(name)
print(age)
print(male)

s = p = a = m = 15
print(s)
print(p)
print(a)
print(m)

### Type Casting ###
# You can use int (or the data type you want) to change a data type to another
print(name + ': ' + str(age))
# Keep in mind when converting floats to ints, the number will be truncated
# Ex: 10.9 will be 10, so always add 0.5 to a number when you want to round