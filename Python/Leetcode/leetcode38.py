def countAndSay(n: int) -> str:
    print(n)
    if n == 1:
        return "1"
    else:
        rThis = ""
        value = countAndSay(n -1)
        i = 0
        counter = []
        while i < len(value):
            ith = value[i]
            if len(counter) == 0 or ith == counter[-1]:
                counter.append(ith)
            else:
                length = len(counter)
                rThis += str(length) + counter[0]
                counter = []
            i += 1
        if len(counter) > 0:
            length = len(counter)
            rThis += str(length) + counter[0]
        print(rThis)
        return rThis

#######################################################
from typing import final
@final
class Colors:
    RED = '\033[91m'
    GREEN = '\033[92m'
    BLUE = '\033[94m'
    WARNING = '\033[93m'
    NC = '\033[0m'

# Test case 1
n = 1
result = countAndSay(n)
print(f"Test case 1: {result}")
if result == "1":
    print(f"{Colors.GREEN}Passes{Colors.NC}\n")
else:
    print(f"{Colors.RED}Fails{Colors.NC}\n")

# Test case 2
n = 4
result = countAndSay(n)
print(f"Test case 1: {result}")
if result == "1211":
    print(f"{Colors.GREEN}Passes{Colors.NC}\n")
else:
    print(f"{Colors.RED}Fails{Colors.NC}\n")
