// Handling exception thrown by a function.
  
#include <iostream>                                 //Line 1
#include "divisionByZero.h"                         //Line 2
 
using namespace std;                                //Line 3
 
void doDivision();                                  //Line 4

int main()                                          //Line 5
{                                                   //Line 6
    doDivision();                                   //Line 7

    return 0;                                       //Line 8
}                                                   //Line 9

void doDivision()                                   //Line 10
{                                                   //Line 11
    int dividend, divisor, quotient;                //Line 12

    try                                             //Line 13
    {                                               //Line 14
        cout << "Line 15: Enter the dividend: ";    //Line 15
        cin >> dividend;                            //Line 16
        cout << endl;                               //Line 17

        cout << "Line 18: Enter the divisor: ";     //Line 18
        cin >> divisor;                             //Line 19
        cout << endl;                               //Line 20

        if (divisor == 0)                           //Line 21
            throw divisionByZero();                 //Line 22

        quotient = dividend / divisor;              //Line 23
        cout << "Line 24: Quotient = " << quotient
             << endl;                               //Line 24
    }                                               //Line 25
    catch (divisionByZero divByZeroObj)             //Line 26
    {                                               //Line 27
        cout << "Line 28: In the function "
             << "doDivision: " 
             << divByZeroObj.what() << endl;        //Line 28
    }                                               //Line 29
}                                                   //Line 30

