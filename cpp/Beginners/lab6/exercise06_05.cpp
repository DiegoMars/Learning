// Diego Martinez
// Created: July 16, 2024
#include <iostream>
using namespace std;

void displaySortedNumbers(double num1, double num2, double num3){
    double temp;
    if (num1 > num2){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num1 > num3){
        temp = num1;
        num1 = num3;
        num3 = temp;
    }
    if (num2 > num3){
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    cout << "The sorted numbers are " << num1 << " " << num2 << " " << num3;
}

int main(){
    double n1;
    double n2;
    double n3;
    cout << "Enter three numbers: " << endl;
    cin >> n1 >> n2 >> n3;
    displaySortedNumbers(double(n1), double(n2), double(n3));

    return 0;
}
// Output:
/*
    Enter three numbers: 
    2 1 3
    The sorted numbers are 1 2 3
*/