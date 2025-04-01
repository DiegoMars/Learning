import math

def composite(n):
    i = 2
    square = math.ceil(math.sqrt(n))
    while (i < square):
        if (n % i == 0):
            return i
        elif (i % int(square/100) == 0):
            print(f'{int((i/square) * 100)+1}% there!')
        i += 1
    return 0

num = int(input("Enter number: "))
while (num != -1):
    out = composite(num)
    if (out == 0):
        print("Prime")
    else:
        print(f'Composite: {out}')
    num = int(input("Enter number: "))
