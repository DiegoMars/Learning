// Diego Martinez
// Created: June 14, 2024
#include <iostream>
using namespace std;

int main(){
    double celsius;
    cout << "Enter a degree in Celsius: ";
    cin >> celsius;
    double fahrenheit = (9.0 / 5) * celsius + 32;
    cout << "Fahrenheit degree is " << fahrenheit << endl;

    return 0;
}

// Output
/*
    Enter a degree in Celsius: 100
    Fahrenheit degree is 212
*/