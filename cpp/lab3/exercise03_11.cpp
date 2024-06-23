// Diego Martinez
// Created: June 20, 2024
#include <iostream>
using namespace std;

int main() {
    double weight;
    cout << "Enter package weight: ";
    cin >> weight;
    if (weight > 20) {
        cout << "The package cannot be shipped.";
    } else {
        if (weight > 10) {
            cout << "The shipping cost is $10.5" << endl;
        } else {
            if (weight > 3) {
                cout << "The shipping cost is $8.5" << endl;
            } else {
                if (weight > 1) {
                    cout << "The shipping cost is $5.5" << endl;
                } else {
                    cout << "The shipping cost is $3.5" << endl;
                }
            }
        }
    }

    return 0;
}

// Output
/*
    Enter package weight: 1
    The shipping cost is $3.5
*/