// Diego Martinez
// Created: December 8, 2024

#include "GeometricObject.h"
#include "Triangle.h"
#include <iostream>
using namespace std;

int main()
{
    double side1;
    double side2;
    double side3;
    string color;
    bool filled;

    cout << "Please enter 3 sides: " << endl;
    cin >> side1 >> side2 >> side3;
    cout << "Enter a color: " << endl;
    cin >> color;
    cout << "Please enter 1 for filled, or 0: " << endl;
    cin >> filled;

    Triangle tri(side1, side2, side3, color, filled);
    cout << "Area: " << tri.getArea() << endl;
    cout << "Perimeter: " << tri.getPerimeter() << endl;
    cout << "Color: " << tri.getColor() << endl;
    cout << "Filled: ";
    if (filled) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}

// Output
/*
    Please enter 3 sides:
    1
    1
    1
    Enter a color:
    Blue
    Please enter 1 for filled, or 0:
    1
    Area: 0.433013
    Perimeter: 3
    Color: Blue
    Filled: True
*/