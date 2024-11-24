// Diego Martinez
// Created: Nov 24, 2024

#include <iostream>
using namespace std;

template<typename T>
void swapNums(T& num1, T& num2) {
    T ph = num1;
    num1 = num2;
    num2 = ph;
}

int main() {
    int test1 = 1;
    int test2 = 2;
    double test3 = 1;
    double test4 = 2;
    string test5 = "AB";
    string test6 = "CD";
    swapNums(test1, test2);
    cout << test1 << " " << test2 << endl;
    swapNums(test3, test4);
    cout << test3 << " " << test4 << endl;
    swapNums(test5, test6);
    cout << test5 << " " << test6 << endl;

    return 0;
}

// Output
/*
    2 1
    2 1
    CD AB
*/