# Diego Martinez
# Math 272

# Imports
import math

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
# 5) Output the shares (Idk what else can be outputted)


def prime(n):
    for i in range(2, int(math.sqrt(abs(n))) + 1):
        if (n % i == 0):
            return False
    return True


def greaterPrime(number):
    primeNumber = number+1
    while (not prime(primeNumber)):
        primeNumber += 1
    return primeNumber


def encrpt(secret, k, n):
    if (k > n):
        print("ERROR: Threshold greater than the number of shares")
        return ("Error")
    degree = k-1
    if (secret >= k and secret >= n):
        tempMod = secret
    elif (k >= secret and k >= n):
        tempMod = k
    else:
        tempMod = n
    modulus = greaterPrime(tempMod)


### Running Code ###
encrpt(1234, 3, 5)
