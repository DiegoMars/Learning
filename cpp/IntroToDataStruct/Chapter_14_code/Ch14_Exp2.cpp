// Checking division by zero.

#include <iostream>                                 //Line 1
  
using namespace std;                                //Line 2
 
int main()                                          //Line 3
{                                                   //Line 4
    int dividend, divisor, quotient;                //Line 5

    cout << "Line 6: Enter the dividend: ";         //Line 6
    cin >> dividend;                                //Line 7
    cout << endl;                                   //Line 8

    cout << "Line 9: Enter the divisor: ";          //Line 9
    cin >> divisor;                                 //Line 10
    cout << endl;                                   //Line 11

    if (divisor != 0)                               //Line 12
    {                                               //Line 13
        quotient = dividend / divisor;              //Line 14
        cout << "Line 15: Quotient = " << quotient 
             << endl;                               //Line 15
    }
    else                                            //Line 16
        cout << "Line 17: Cannot divide by zero." 
             << endl;                               //Line 17

    return 0;                                       //Line 18
}                                                   //Line 19

