// Diego Martinez
// Created: Nov 14, 2024

#include <iostream>
using namespace std;

int findLargest(int* arr, int size) {
    int largest = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) > largest) {
            largest = *(arr + i);
        }
    }
    return largest;
}

int main() {
    int numbers[] = {6, 7, 9, 10, 15, 3, 99, -21};
    int size = 8;
    cout << "The max is " << findLargest(numbers, size) << endl;

    return 0;
}

// Output
/*
    
*/
