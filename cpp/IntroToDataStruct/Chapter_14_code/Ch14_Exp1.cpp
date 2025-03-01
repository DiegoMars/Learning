// Division by zero.
   
#include <iostream>                             //Line 1

using namespace std;                            //Line 2
  
int main()                                      //Line 3
{                                               //Line 4
    int dividend, divisor, quotient;            //Line 5

    cout << "Line 6: Enter the dividend: ";     //Line 6
    cin >> dividend;                            //Line 7
    cout << endl;                               //Line 8

    cout << "Line 9: Enter the divisor: ";      //Line 9
    cin >> divisor;                             //Line 10
    cout << endl;                               //Line 11

    quotient = dividend / divisor;              //Line 12
    cout << "Line 13: Quotient = " << quotient
         << endl;                               //Line 13

    return 0;                                   //Line 14
}                                               //Line 15
