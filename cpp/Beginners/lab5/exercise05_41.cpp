// Diego Martinez
// Created: July 7, 2024
#include <iostream>
using namespace std;

int main() {
    int max = 0;
    int count = 0;
    int temp;
    cout << "Enter an integer (0: for end of input): ";
    cin >> temp;
    while (temp != 0){
        if (temp > max) {
            max = temp;
            count = 1;
        } else {
            if (temp == max) {
                ++count;
            }
        }
        cout << "Enter an integer (0: for end of input): ";
        cin >> temp;
    }
    cout << "The largest number is " << max << endl;
    cout << "The occurrence count of the largest number is " << count << endl;

    return 0;
}
// Output
/*
    Enter an integer (0: for end of input): 3
    Enter an integer (0: for end of input): 5
    Enter an integer (0: for end of input): 2
    Enter an integer (0: for end of input): 5
    Enter an integer (0: for end of input): 5
    Enter an integer (0: for end of input): 5
    Enter an integer (0: for end of input): 0
    The largest number is 5
    The occurrence count of the largest number is 4
*/