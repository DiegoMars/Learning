// Using a user-defined exception class.
   
#include <iostream>                                 //Line 1
 
using namespace std;                                //Line 2

class divByZero                                     //Line 3
{};                                                 //Line 4

int main()                                          //Line 5
{                                                   //Line 6
    int dividend, divisor, quotient;                //Line 7

    try                                             //Line 8
    {                                               //Line 9
        cout << "Line 10: Enter the dividend: ";    //Line 10
        cin >> dividend;                            //Line 11
        cout << endl;                               //Line 12

        cout << "Line 13: Enter the divisor: ";     //Line 13
        cin >> divisor;                             //Line 14
        cout << endl;                               //Line 15

        if (divisor == 0)                           //Line 16
            throw divByZero();                      //Line 17

        quotient = dividend / divisor;              //Line 18
        cout << "Line 19: Quotient = " << quotient 			
             << endl;                               //Line 19
    }                                               //Line 20
    catch (divByZero)                               //Line 21
    {                                               //Line 22
        cout << "Line 23: Division by zero!" 
             << endl;                               //Line 23
    }                                               //Line 24

    return 0;                                       //Line 25
}                                                   //Line 26
