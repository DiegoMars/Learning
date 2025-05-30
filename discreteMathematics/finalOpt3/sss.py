# Diego Martinez
# Math 272

# Imports
import math
import random


### Encrypt ###
# 1) Input a secret, some threshold K, and some number of shares N
#    Need to check that the number of shares is the same as the number of the
#    threshold or greater
# 2) Calculate what degree polynomial would be needed
#    Note that the degree needed is K-1
# 3) Get what the value of the modulus should be a prime number greater than
#    the secret, the number of shares, and the coefficients (I keep mixing this
#    up with threshold, but lets call it modulus)
# 4) Populate random coefficients, making sure that it is less than the prime
#    number, then get the number of shares
# 5) Output the shares by getting a random x and get the respective y by
#    multiplying each coefficient by x, add them together, and add the constant

# Checks if number is prime
def prime(n):
    for i in range(2, int(math.sqrt(abs(n))) + 1):
        if (n % i == 0):
            return False
    return True


# Gets prime number bigger than number
def greaterPrime(number):
    primeNumber = number+1
    while (not prime(primeNumber)):
        primeNumber += 1
    return primeNumber


def generateY(polynomial, x, modulus):
    y = polynomial[0]  # Adds constant
    for i in range(len(polynomial)-1):
        y += x**(i+1)  # Multiply each coefficent by x, then add to y
    return (y % modulus)  # Keeps the y under modulus


def encrypt(secret, k, n):
    if (k > n):
        print("ERROR: Threshold greater than the number of shares")
        exit(1)
    degree = k-1

    # Grabs the prime number greater than the biggest input number
    if (secret >= k and secret >= n):
        tempMod = secret
    elif (k >= secret and k >= n):
        tempMod = k
    else:
        tempMod = n
    modulus = greaterPrime(tempMod)

    # This represents the the coefficients and the constant
    polynomial = [secret]
    for i in range(degree):
        # Populate the random coefficients
        polynomial.append(random.randint(1, modulus-1))

    # Generates shares
    shares = []
    for i in range(n):
        share = []
        x = random.randint(1, 1000)
        y = generateY(polynomial, x, modulus)
        share.append(x)
        share.append(y)
        shares.append(share)
    return (shares, modulus)


### Decrypt ###
# 1) Input shares and the modulus
# 2) Find the Lagrange polynomial for every point given at point 0 (or do the
#    Lagrange stuff at x=0)
# 2a)Reminder that we should not use regular division because of the modulus
#    stuff, we need to find the mod inverse of the divisor and multiply it by
#    the dividend instead.
# 2b)To find the mod inverse, we are gonna brute force finding it, where we
#    just from 1 until we find the inverse, or a number such that the number
#    times what we are trying to find the inverse of, the mod of that would be
#    one.
# 2c)The correct way would be to do the extended Euclidean algorithm, but this
#    is easier for now
# 3) Multiply each Lagrange polynomial by their respective y
# 3a)Note that after this step, we have to get the mod of the product of the
#    polynomial and the
# 4) Add up all of the Lagrange polynomial values at x=0 multiplied by y
# 5) Output final result, which should be the constant of the polynomial, in
#    other words the secret

# To find mod inverse of the number
def modInverse(number, modulus):
    inverse = 1
    while ((number*inverse) % modulus != 1):
        inverse += 1
    return (inverse)


# find the lagrange value at x=0 of point
def lagrange(sharepos, shares, modulus):
    dividend = 1
    divisor = 1
    # Go through all of the point's and do the fraction
    for i in range(len(shares)):
        if (i == sharepos):
            continue
        xj = shares[i][0]
        xi = shares[sharepos][0]
        # Do product of the current point's step
        dividend *= (-1 * xj)
        divisor *= (xi + (-1 * xj))
    inverse = modInverse(divisor, modulus)
    lagrangeValue = (dividend * inverse)
    return lagrangeValue


def decrypt(shares, modulus):
    secret = 0
    lValues = []
    # Get the lagrange of every point at x=0
    for i in range(len(shares)):
        lValues.append(lagrange(i, shares, modulus))
    # Multiply each lagrange value by their respective y value, then add to the
    # secret value
    for i in range(len(shares)):
        secret += shares[i][1]*lValues[i]
    # Get the modulus of all the combined values to finally get the secret
    secret %= modulus
    return (secret)


### Running Code ###
do = input("Random everything (y,n): ")
do = do.lower()
if (do == "y"):
    secret = random.randint(100, 500)
    k = random.randint(3, 6)  # Threshold
    n = random.randint(6, 10)  # Number of shares
else:
    secret = int(input("Enter secret: "))
    k = int(input("Enter threshold: "))
    n = int(input("Enter number of shares: "))
    print("")

shares, modulus = encrypt(secret, k, n)
print(f"Secret: {secret}\nThreshold: {k}\nNumber of shares: {n}")
print(f"Shares: {shares}")
print(f"Modulus: {modulus}")
decryptedSecret = decrypt(shares, modulus)
print(f"decryptedSecret: {decryptedSecret}")
exit(0)
