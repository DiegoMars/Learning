//The user program that uses the class integerManipulation

#include <iostream>                                 //Line 1
#include "integerManipulaiton.h"                    //Line 2

using namespace std;                                //Line 3

int main()                                          //Line 4
{                                                   //Line 5
    integerManipulation number;                     //Line 6

    long long num;                                  //Line 7

    cout << "Enter an integer: ";                   //Line 8
    cin >> num;                                     //Line 9
    cout << endl;                                   //Line 10

    number.setNum(num);                             //Line 11

    number.classifyDigits();                        //Line 12

    cout << number.getNum() << "------" << endl
         << "The number of even digits: "
         << number.getEvensCount() << endl
         << "The number of zeros: "
         << number.getZerosCount() << endl
         << "The number of odd digits: "
         << number.getOddsCount() << endl;          //Line 13

    return 0;                                       //Line 14
}//end main                                         //Line 15
