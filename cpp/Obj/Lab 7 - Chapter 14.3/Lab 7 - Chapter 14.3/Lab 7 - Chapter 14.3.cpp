// Diego Martinez
// Created: December 1, 2024

#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
    Circle c1;
    Circle c2(2);

    cout << (c1 < c2) << endl;
    cout << (c1 <= c2) << endl;
    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;
    cout << (c1 > c2) << endl;
    cout << (c1 >= c2) << endl;

    return 0;
}

// Output
/*
    1
    1
    0
    1
    0
    0
*/