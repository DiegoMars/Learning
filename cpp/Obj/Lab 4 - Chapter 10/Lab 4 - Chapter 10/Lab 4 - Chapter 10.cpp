// Diego Martinez
// Created: Nov 10, 2024
#include <iostream>
using namespace std;

class Location {
public:
    // Data Fields
    int row;
    int column;
    double maxValue;

    // Constructors
    Location() {
        row = 0;
        column = 0;
        maxValue = 0.0;
    }
    Location(int r, int c, double val) {
        row = r;
        column = c;
        maxValue = val;
    }
};

const int ROW_SIZE = 3;
const int COLUMN_SIZE = 4;
Location locateLargest(const double a[][COLUMN_SIZE]) {
    // Initialize the largest location object
    Location l(0, 0, 0.0);

    // Look for largest location object
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            if (a[i][j] > l.maxValue) {
                l.row = i;
                l.column = j;
                l.maxValue = a[i][j];
            }
        }
    }

    return l;
}

int main() {
    // Initialize 2d array
    double arr[ROW_SIZE][COLUMN_SIZE];
    cout << "Enter a 3 by 4 two-dimensional array:";
    // Adds values to the 2d array
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            cin >> arr[i][j];
        }
    }

    Location largest = locateLargest(arr); // Grabs the largest location
    // Outputs te largest
    cout << "The location of the largest element is " << largest.maxValue << " at (" << largest.row << ", " << largest.column << ")";

    return 0;
}

// Output
/*
    The location of the largest element is 45 at (1, 2)
*/