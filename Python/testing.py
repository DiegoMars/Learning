def binarySearch(nums: list[int], t: int, k: int) -> int:
    if len(nums) == 0:
        return -1
    if len(nums) == 1:
        if nums[0] == t:
            return 0
        return -1
    l = len(nums)
    flag = 0
    low = k
    high = (l + k - 1) % l
    while flag < l and (low - k) % l <= (high - k) % l:
        tLow = (low - k) % l
        tHigh = (high - k) % l
        tMid = tLow + (tHigh - tLow) // 2
        mid = (tMid + k) % l
        flag += 1
        if nums[mid] == t:
            return mid
        elif nums[mid] < t:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def search(nums: list[int], target: int) -> int:
    k = 0
    for i in range(1, len(nums)):
        if nums[i - 1] > nums[i]:
            k = i
            break
    return binarySearch(nums, target, k)

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
nums = [4,5,6,7,0,1,2]
t = 0
result = search(nums, t)
print(f"Test case 1: {result}")
if result == 4:
    print(f"{Colors.GREEN}Passes{Colors.NC}\n")
else:
    print(f"{Colors.RED}Fails{Colors.NC}\n")


# Test case 2
nums = [4,5,6,7,0,1,2]
t = 3
result = search(nums, t)
print(f"Test case 2: {result}")
if result == -1:
    print(f"{Colors.GREEN}Passes{Colors.NC}\n")
else:
    print(f"{Colors.RED}Fails{Colors.NC}\n")

# Test case 3
nums = [1]
t = 0
result = search(nums, t)
print(f"Test case 3: {result}")
if result == -1:
    print(f"{Colors.GREEN}Passes{Colors.NC}\n")
else:
    print(f"{Colors.RED}Fails{Colors.NC}\n")

# Test case 4
nums = [1,3,5]
t = 0
result = search(nums, t)
print(f"Test case 4: {result}")
if result == -1:
    print(f"{Colors.GREEN}Passes{Colors.NC}\n")
else:
    print(f"{Colors.RED}Fails{Colors.NC}\n")
