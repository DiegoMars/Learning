// Diego Martinez
// Created: June 29, 2024
#include <iostream>
using namespace std;

int main() {
    char letter;
    int num;
    int pos;
    cout << "Enter an uppercase letter: ";
    cin >> letter;
    if ((int(letter) >= 65 && int(letter) <= 90) || (int(letter) >= 97 && int(letter) <= 122)) {
        pos = int(toupper(letter)) - 64;
        if (pos >= 1 && pos <= 3){
            num = 2;
        }
        if (pos >= 4 && pos <= 6){
            num = 3;
        }
        if (pos >= 7 && pos <= 9){
            num = 4;
        }
        if (pos >= 10 && pos <= 12){
            num = 5;
        }
        if (pos >= 13 && pos <= 15){
            num = 6;
        }
        if (pos >= 16 && pos <= 19){
            num = 7;
        }
        if (pos >= 20 && pos <= 22){
            num = 8;
        }
        if (pos >= 23 && pos <= 26){
            num = 9;
        }
        cout << "The corresponding number is " << num << endl;
    } else {
        cout << letter << " is an invalid input " << endl;
    }

    return 0;
}