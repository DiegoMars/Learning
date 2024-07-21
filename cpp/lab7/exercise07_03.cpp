// Diego Martinez
// Created July 19, 2024
#include <iostream>
using namespace std;

int main(){
    int input;
    int aInputs[100];
    int size = 0;
    cout << "Enter the numbers between 1 and 100 ending with 0:" << endl;

    // Grab all inputs
    while (true){
        cin >> input; // Accept input

        // End loop if input = 0
        if (input == 0){
            break;
        }
        
        // Addes the input to aInputs array
        aInputs[size] = input;
        size++;
    }

    // Counts occurences
    int count;
    // Repeats following process for all numbers from 1 to 100
    for (int i = 1; i<=100; i++){
        count = 0;
        // Checks the number of occurences for a number, and outputs accordingly
        for (int j = 0; j<size; j++){
            if (aInputs[j] == i){
                count++;
            }
        }
        if (count > 1){
            cout << i << " occurs " << count << " times" << endl;
        }
        if (count == 1){
            cout << i << " occurs " << count << " time" << endl;   
        }
    }

    return 0;
}
// Output:
/*
    Enter the numbers between 1 and 100 ending with 0:
    2
    5
    6
    5
    4
    3
    23
    43
    2
    0
    2 occurs 2 times
    3 occurs 1 time
    4 occurs 1 time
    5 occurs 2 times
    6 occurs 1 time
    23 occurs 1 time
    43 occurs 1 time
*/