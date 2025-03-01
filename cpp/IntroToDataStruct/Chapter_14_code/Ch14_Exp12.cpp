// Using user-defined exception class divisionByZero with a 
// specific error message.
   
#include <iostream>                                     //Line 1
#include "divisionByZero.h"                             //Line 2

using namespace std;                                    //Line 3

int main()                                              //Line 4
{                                                       //Line 5
    int dividend, divisor, quotient;                    //Line 6

    try                                                 //Line 7
    {                                                   //Line 8
        cout << "Line 9: Enter the dividend: ";         //Line 9
        cin >> dividend;                                //Line 10
        cout << endl;                                   //Line 11

        cout << "Line 12: Enter the divisor: ";         //Line 12
        cin >> divisor;                                 //Line 13
        cout << endl;                                   //Line 14

        if (divisor == 0)                               //Line 15
           throw divisionByZero("Found division by 0"); //Line 16

        quotient = dividend / divisor;                  //Line 17
        cout << "Line 12: Quotient = " << quotient
             << endl;                                   //Line 18
    }                                                   //Line 19
    catch(divisionByZero divByZeroObj)                  //Line 20
    {                                                   //Line 21
        cout << "Line 22: In the divisionByZero "
             << "catch block: "
             << divByZeroObj.what() << endl;            //Line 22
    }                                                   //Line 23

    return 0;                                           //Line 24
}                                                       //Line 25
