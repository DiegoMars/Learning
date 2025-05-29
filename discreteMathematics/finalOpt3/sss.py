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
        y += x**(i+1)
    return (y % modulus)  # Keeps the y under modulus


def encrpt(secret, k, n):
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


### Running Code ###
shares, modulus = encrpt(65, 2, 4)
print(shares)
print(modulus)
