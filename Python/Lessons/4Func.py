### Math Functions ###
import math #make sure to have all your imports on top
pi = 3.14

# rounds up
print(math.ceil(pi))
# rounds down
print(math.floor(pi))
# absolute value
print(math.fabs(pi))
# self explanatory
print(math.factorial(4))
# power where the its the first value by the second
print(math.pow(2,2))
# square root
print(math.sqrt(4))
# cosine (in radians)
print(math.cos((90*pi)/180))
# sine (in radians)
print(math.sin((90*pi)/180))
# tangent (in radians)
print(math.tan((90*pi)/180))
# distance between 2 points
print(math.dist([1,0],[1,1]))

### Random functions ###
import random #make sure to have all your imports on top

# random number between 0 and 1 (float)
print(random.random())
# random number between 1st int and 2nd int (int)
print(random.randint(0,10))
# random number between 1st value and 2nd value (float)
print(random.uniform(0,10))
# random number between 1st value and 2nd value, not including 2nd value (int)
print(random.randrange(0,10))
print(random.randrange(0,10,2)) #goes by steps of 2
# returns random element from a list or string
print(random.choice("diego"))
# shuffles list
# print(random.shuffle())