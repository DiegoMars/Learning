import string

def textToNums(text):
    d = {'A': '01', 'B': '02', 'C': '03', 'D': '04', 'E': '05', 'F': '06', 'G': '07', 'H': '08', 'I': '09', 
         'J': '10', 'K': '11', 'L': '12', 'M': '13', 'N': '14', 'O': '15', 'P': '16', 'Q': '17', 'R': '18', 
         'S': '19', 'T': '20', 'U': '21', 'V': '22', 'W': '23', 'X': '24', 'Y': '25', 'Z': '26', " ":'27', ".":'28'}
    rThis = ""
    for char in text:
        rThis = rThis + d[char]
    return(rThis)
    
def numsToText(numbers):
    d = {'01': 'A', '02': 'B', '03': 'C', '04': 'D', '05': 'E', '06': 'F', '07': 'G', '08': 'H', '09': 'I', 
         '10': 'J', '11': 'K', '12': 'L', '13': 'M', '14': 'N', '15': 'O', '16': 'P', '17': 'Q', '18': 'R', 
         '19': 'S', '20': 'T', '21': 'U', '22': 'V', '23': 'W', '24': 'X', '25': 'Y', '26': 'Z', '27':" ", '28':"."}
    splitNums = []
    rThis = ""
    while numbers:
        splitNums.append(numbers[:2])
        numbers = numbers[2:]
    print(splitNums)
    for num in splitNums:
        rThis += d[num]
    return(rThis)

def encrypt(m, k, N):
    c = (m + k) % N
    return c

def decrypt(c, k, N):
    m = (c - k) % N
    return m


####################################
#                Main              #
####################################
iP = input("Enter string: ").upper()
print(f'Numbers: {textToNums(iP)}')
# print(f'Letters: {numsToText(iP)}')
k = 2191
N = 3391
# c = encrypt(2317, k, N)
# print(c)
# m = encrypt(c, k, N)
# print(m)
# Test input: ATTACK AT DAWN

# 0409190318052005