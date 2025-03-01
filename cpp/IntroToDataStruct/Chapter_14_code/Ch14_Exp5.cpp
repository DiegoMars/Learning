// Handling division by zero exception.

#include <iostream>                                 //Line 1
  
using namespace std;                                //Line 2
 
int main()                                          //Line 3
{                                                   //Line 4
    int dividend, divisor, quotient;                //Line 5

    try                                             //Line 6
    {                                               //Line 7
        cout << "Line 8: Enter the dividend: ";     //Line 8
        cin >> dividend;                            //Line 9
        cout << endl;                               //Line 10

        cout << "Line 11: Enter the divisor: ";     //Line 11
        cin >> divisor;                             //Line 12
        cout << endl;                               //Line 13

        if (divisor == 0)                           //Line 14
            throw 0;                                //Line 15

        quotient = dividend / divisor;              //Line 16

        cout << "Line 17: Quotient = " << quotient 
             << endl;                               //Line 17
    }                                               //Line 18
    catch (int)                                     //Line 19
    {                                               //Line 20
        cout << "Line 21: Division by 0." << endl;  //Line 21
    }                                               //Line 22

    return 0;                                       //Line 23
}                                                   //Line 24
