// Diego Martinez
// Created: Nov 3, 2024

#include <iostream>
using namespace std;

int main()
{
    // Initialize array
    bool lockers[100];
    for (int i = 0; i < 100; i++) {
        lockers[i] = false;
    }

    // Goes through lockers
    for (int i = 0; i < 100; i++) {
        for (int j = i; j < 100; j = j + i + 1) {
            lockers[j] = !lockers[j];
        }
    }

    // Prints what lockers are open
    for (int i = 0; i < 100; i++) {
        if (lockers[i]) {
            cout << i+1 << " ";
        }
    }

    return 0;
}

// Output
/*
    1 4 9 16 25 36 49 64 81 100
*/