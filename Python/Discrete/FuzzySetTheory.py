# Imports
import random

#                                 #
# Part 1: fuzz set implementation #
#                                 #
r = {"Alice":0.4, "Brian":0.8, "Fred":0.2, "Oscar":0.9, "Rita":0.7}

#                                                     #
# Part 2: dynamically created fuzzy set implmentation #
#                                                     #
def loyalty(dictionary):
    rThis = {}  # Dictionary with names and their loyalty value
    for name in dictionary: # Loop through all the names
        purchases = dictionary.get(name)
        if (purchases < 5):
            loyaltyValue = 0
        elif (purchases >= 5 and purchases <= 10):
            loyaltyValue = (purchases-5)/5
        else:
            loyaltyValue = 1
        rThis[name] = loyaltyValue
    return rThis

purchaseDictionary = {"Dave":random.randint(0, 10),
                      "Sam":random.randint(0, 10),
                      "Diego":random.randint(0, 10),
                      "Josh":random.randint(0, 10),
                      "David":random.randint(0, 10),
                      "Roxanne":random.randint(0, 10)}
loyaltyDictionary = loyalty(purchaseDictionary)
print("Part 2")
for name in loyaltyDictionary:
    print(name, loyaltyDictionary.get(name))

#                                                  #
# Part 3: complement of a fuzzy set implementation #
#                                                  #
def fuzzyComplement(dictionary):
    rThis = {} # Will store the complement values
    for name in dictionary:
        value = (10 - int(dictionary.get(name)*10))/10 # Finds the complementary value
                                                       # By finding 1 - value
                                                       # Looks like a bit more because
                                                       # of rounding
        rThis[name] = value # Add new pair to dictionary
    return rThis

rComplement = fuzzyComplement(r)
print("\nPart 3")
for id in rComplement:
    print(id, rComplement.get(id))

#                                             #
# Part 4: union of 2 fuzzy sets implementaion #
#                                             #
f = {"Alice":0.6, "Brian":0.9, "Fred":0.4, "Oscar":0.1, "Rita":0.5}
# r is already defined
def fuzzyUnion(set1, set2):
    rThis = {} # Will store union values
    values1 = [] # Values of set1
    values2 = [] # Values of set2
    names = []
    for value1 in set1:
        values1.append(set1.get(value1)) # Puts the values of set1 in a list
        values2.append(set2.get(value1)) # Puts the values of set2 in a list
        names.append(value1)
    for i in range(len(set1)):
        x = values1[i]
        y = values2[i]
        maximum = max(x,y)
        rThis[names[i]] = maximum
    return rThis

fUr = fuzzyUnion(f,r)
print("\nPart 4")
for id in fUr:
    print(id, fUr.get(id))

#                                                    #
# Part 5: intersection of 2 fuzzy sets implementaion #
#                                                    #
def fuzzyUnion(set1, set2):
    rThis = {} # Will store union values
    values1 = [] # Values of set1
    values2 = [] # Values of set2
    names = []
    for value1 in set1:
        values1.append(set1.get(value1)) # Puts the values of set1 in a list
        values2.append(set2.get(value1)) # Puts the values of set2 in a list
        names.append(value1)
    for i in range(len(set1)):
        x = values1[i]
        y = values2[i]
        minimum = min(x,y)
        rThis[names[i]] = minimum
    return rThis

fUr = fuzzyUnion(f,r)
print("\nPart 5")
for id in fUr:
    print(id, fUr.get(id))