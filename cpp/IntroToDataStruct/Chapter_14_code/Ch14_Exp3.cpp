// Division by zero and the assert function.

#include <iostream>                             //Line 1
#include <cassert>                              //Line 2

using namespace std;                            //Line 3
 
int main()                                      //Line 4
{                                               //Line 5
    int dividend, divisor, quotient;            //Line 6

    cout << "Line 7: Enter the dividend: ";     //Line 7
    cin >> dividend;                            //Line 8
    cout << endl;                               //Line 9

    cout << "Line 10: Enter the divisor: ";     //Line 10
    cin >> divisor;                             //Line 11
    cout << endl;                               //Line 12

    assert(divisor != 0);                       //Line 13
    quotient = dividend / divisor;              //Line 14

    cout << "Line 15: Quotient = " << quotient 
         << endl;                               //Line 15

    return 0;                                   //Line 16
}                                               //Line 17
