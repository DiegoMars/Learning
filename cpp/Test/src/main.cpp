#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int t) {
    int low = 0;
    int high = nums.size() -1;
    bool flag = false;
    int mid;
    int value;
    while (low <= high) {
        flag = true;
        mid = low + (high - low) / 2;
        value = nums[mid];
        if  (value == t) {
            return mid;
        }
        else if (t > value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if (flag) {
        return mid;
    }
    return -1;
}

int searchInsert(vector<int>& nums, int target) {
    int pos = binarySearch(nums, target);
    int value = nums[pos];
    if (value != target) {
        if (value < target){
            return pos +1;
        }
        if (pos > 0) {
            return pos -1;
        }
        return 0;
    }
    return pos;
}

int main() {
    vector<int> nums;
    int target;
    int value;

    // Test case 1
    nums = {1,3,5,6};
    target = 5;
    value = searchInsert(nums, target);
    if (value != 2){
        cout << "Test case 1: fail, value: " << value << endl;
    } else {
        cout << "Test case 1: pass" << endl;
    }

    // Test case 2
    nums = {1,3,5,6};
    target = 2;
    value = searchInsert(nums, target);
    if (value != 1) {
        cout << "Test case 2: fail, value: " << value << endl;
    } else {
        cout << "Test case 2: pass" << endl;
    }

    // Test case 3
    nums = {1,3,5,6};
    target = 0;
    value = searchInsert(nums, target);
    if (value != 0) {
        cout << "Test case 3: fail, value: " << value << endl;
    } else {
        cout << "Test case 3: pass" << endl;
    }

    return 0;
}
