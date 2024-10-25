import random

def outputMatrix(size):
    matrix = []

    #  Create matrix
    for i in range(size):                  # interates row
        new = []
        for j in range(size):              # iterates collomn
            if j == 0:                     # if first collomn, put num
                new.append(i+1)
            elif i == 0:                   # if first row, put num
                new.append(j+1)
            else:                          # mulitiply the colomn num by row num
                new.append((i+1)*(j+1))
        matrix.append(new)
    
    # Print output
    output = ""
    for row in (matrix):                  # iterates row
        for num in (row):              # interates collomn
            output += str(f"{num} ")
        output += "\n"
    print(output)

# runs case
randomNum = random.randint(4,6)
print(randomNum)
outputMatrix(randomNum)