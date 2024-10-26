// Diego Martinez
// Created July 24, 2024
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("data.txt");

    // Check if file opened successfully
    if (!outFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    // Seed the random number generator
    srand(0);

    // Write 100 random integers in the range 0 to 100 to the file
    for (int i = 0; i < 100; ++i) {
        outFile << rand() % 101 << " ";  // Generate numbers from 0 to 100
    }

    // A new line for separation when appending new sets of numbers
    outFile << endl;

    // Close the file stream
    outFile.close();

    return 0;
}
// Output
/*
    Creates txt file
*/