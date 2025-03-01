// Handle division by zero, division by a negative integer,
// and input failure exceptions.
 
#include <iostream>                                 //Line 1
#include <string>                                   //Line 2
   
using namespace std;                                //Line 3

int main()                                          //Line 4
{                                                   //Line 5
    int dividend, divisor = 1, quotient;            //Line 6

    string inpStr 
       = "The input stream is in the fail state.";  //Line 7

    try                                             //Line 8
    {                                               //Line 9
        cout << "Line 10: Enter the dividend: ";    //Line 10
        cin >> dividend;                            //Line 11
        cout << endl;                               //Line 12

        cout << "Line 13: Enter the divisor: ";     //Line 13
        cin >> divisor;                             //Line 14
        cout << endl;                               //Line 15

        if (divisor == 0)                           //Line 16
            throw divisor;                          //Line 17
        else if (divisor < 0)                       //Line 18
            throw string("Negative divisor.");      //Line 19
        else if (!cin)                              //Line 20
            throw inpStr;                           //Line 21

        quotient = dividend / divisor;              //Line 22

        cout << "Line 23: Quotient = " << quotient		
             << endl;                               //Line 23
    }                                               //Line 24
    catch (int x)                                   //Line 25
    {                                               //Line 26
        cout << "Line 27: Division by " << x
             << endl;                               //Line 27
    }                                               //Line 28
    catch (string s)                                //Line 29
    {                                               //Line 30
        cout << "Line 31: " << s << endl;           //Line 31
    }                                               //Line 32

    return 0;                                       //Line 33
}                                                   //Line 34
