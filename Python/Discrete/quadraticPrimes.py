# Imports
import math

# My first thought is to just use a bunch of for loops to compare integers 
# to each other. Very brute force tbh since there is a lottt of comparisons 
# but I think is fine for now till I think of smt better.

def prime(n):
    # We use square root because there is no use going over the bigger numbers
    # when the lower ones so just fine. For example, if we take the square root
    # of 15, we get around 3.87. For a number to be non prime, then we have to
    # a divisor other than 1 and the number itself, and in the case of 15 we have
    # 3 and 5. Since one of the divisors, 3, falls between 2 and 4 (rounded up from
    # 3.87), we know that the the number is not prime, and no need to check the rest.
    for i in range(2, int(math.sqrt(abs(n))) + 1):
        if (n % i == 0):
            return False
    return True # If n is prime, then return true

# One thing about prime numbers is that they are odd (except for 2) so I think that 
# maybe we can cut down comparisons by taking this into account, even if I don't know
# how just yet

# Or actually, if we take n=0 into account, we would need b to always be a prime number,
# so for it's loop we can skip all non prime numbers. Honestly, rather than checking if
# b is prime or not, I'm just going to get a list of prime numbers from -1000 to 1001 and put
# it into a list lmao.
def retrievePrimes(num):
    listOfPrimes = []
    for i in range(-num+1,num):
        if (prime(i)):
            listOfPrimes.append(i)
    return listOfPrimes
# As for a, I can't think of a way to also prove that it has to be prime, so we'll leave as is
# for now

# Using to check how many prime numbers this instance of n^2 + an + b has
def numberOfPrimes(a, b):
    n = 0
    while (prime(pow(n,2) + a*n + b)):
        n += 1
    return n

# Basically loops through every possible a with every possible b to see which combination has the
# highest number of primes
def aAndBLoops():
    listOfBPrimes = retrievePrimes(1001)
    highestNOP = 0; # Stores the highest number of possible prime numbers on an
                               # instance of n^2 + an + b
    aA = 0;           # Stores the a of said instance
    aB = 0;           # Stores the b of said instance
    for a in range(-999,1000):
        for b in listOfBPrimes:
            nOP = numberOfPrimes(a,b)
            if (nOP > highestNOP):
                highestNOP = nOP
                aA = a
                aB = b
    return highestNOP, aA, aB

#          #
# Main Run #
#          #
h, a, b, = aAndBLoops()
print(f'The highest number of {h} prime numbers was found with a combination of a={a} and b={b}')

# Output:
# The highest number of 71 prime numbers was found with a combination of a=-61 and b=971