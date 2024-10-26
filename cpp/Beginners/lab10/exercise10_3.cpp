// Creatied with kids
// Creating August 4, 2024
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Open the file "data.txt" for reading
    ifstream inFile("data.txt");

    // Check if the file was opened successfully
    if (!inFile) {
        cout << "Unable to open file data.txt" << endl;
        return 1;  // Exit with error if file cannot be opened
    }

    int score;
    int total = 0;
    int count = 0;

    // Read scores from the file
    while (inFile >> score) {
        total += score;  // Add each score to the total
        count++;         // Increment the score count
    }

    inFile.close();  // Close the file

    // Calculate and display the total and average
    if (count > 0) {  // Ensure there are scores to avoid division by zero
        double average = static_cast<double>(total) / count;
        cout << "Total of scores: " << total << endl;
        cout << "Average of scores: " << average << endl;
    } else {
        cout << "No scores were found in the file." << endl;
    }

    return 0;
}
// Output
/*
    Total of scores: 5003
    Average of scores: 50.03
*/