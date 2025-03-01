// Question 16.
// Suppose that intArray is an array of integers, and length specifies the number
// of elements in intArray. Also, suppose that low and high are two integers
// such that 0 <= low < length, 0 <= high < length, and low < high. That
// is, low and high are two indices in intArray. Write a recursive definition that
// reverses the elements in intArray between low and high. (2, 3, 4, 6)
#include<iostream>
using namespace std;

void switchNums(int array[], int low, int high){
    int temp;
    if(low < high){
        temp = array[low];
        array[low] = array[high];
        array[high] = temp;
        switchNums(array, low + 1, high - 1);
    } else {
        return;
    }
}

int main(){
    int intArray[10] = {1,2,3,4,5,6,7,8,9};
    int low = 3;
    int high = 7;

    cout << "Original: ";
    for (int i = 0; i < 10; i++){
        cout << intArray[i] << ", ";
    }
    cout << endl;

    switchNums(intArray, low, high);

    cout << "Reversed: ";
    for (int i = 0; i < 10; i++){
        cout << intArray[i] << ", ";
    }
    cout << endl;

    return 0;
}