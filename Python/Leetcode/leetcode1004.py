def longestOnes(nums: list[int], k: int) -> int:
    index = 0
    m = 0
    count = k
    while index < len(nums):
        if nums[index] == 1:
            index += 1
        elif count > 0:
            count -= 1
            index += 1
        else:
            break
    while index < len(nums):
        j = index
        count = k
        while j < len(nums):
            if nums[j] == 1:
                j += 1
            elif count > 0:
                count -= 1
                j += 1
            else:
                break
        m = max(m, j - index)
        print(f"index: {index}, m: {m}")
        index += 1
        # while index < len(nums) and nums[index] == 1:
        #     index += 1
    return m

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
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
result = longestOnes(nums, k)
print(f"Test case 1: {result}")
if result == 6:
    print(f"{Colors.GREEN}Passes{Colors.NC}\n")
else:
    print(f"{Colors.RED}Fails{Colors.NC}\n")

# Test case 2
nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
k = 3
result = longestOnes(nums, k)
print(f"Test case 2: {result}")
if result == 10:
    print(f"{Colors.GREEN}Passes{Colors.NC}\n")
else:
    print(f"{Colors.RED}Fails{Colors.NC}\n")
