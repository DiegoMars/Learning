// Handling exception, in the main function, thrown by another
// function. The function throws the same exception object.
  
#include <iostream>                                   //Line 1
#include "divisionByZero.h"                           //Line 2
 
using namespace std;                                  //Line 3

void doDivision() throw (divisionByZero);             //Line 4

int main()                                            //Line 5
{                                                     //Line 6
    try                                               //Line 7
    {                                                 //Line 8
        doDivision();                                 //Line 9
    }                                                 //Line 10
    catch (divisionByZero divByZeroObj)               //Line 11
    {                                                 //Line 12
        cout << "Line 13: In main: " 
             << divByZeroObj.what() << endl;          //Line 13
    }                                                 //Line 14

    return 0;                                         //Line 15
}                                                     //Line 16

void doDivision() throw (divisionByZero)              //Line 17
{                                                     //Line 18
    int dividend, divisor, quotient;                  //Line 19

    try                                               //Line 20
    {                                                 //Line 21
        cout << "Line 22: Enter the dividend: ";      //Line 22
        cin >> dividend;                              //Line 23
        cout << endl;                                 //Line 24

        cout << "Line 25: Enter the divisor: ";       //Line 25
        cin >> divisor;                               //Line 26
        cout << endl;                                 //Line 27

        if (divisor == 0)                             //Line 28
            throw 
              divisionByZero("Found division by 0!"); //Line 29

        quotient = dividend / divisor;                //Line 30
        cout << "Line 31: Quotient = " << quotient
             << endl;                                 //Line 31
    }                                                 //Line 32
    catch (divisionByZero)                            //Line 33
    {                                                 //Line 34
        throw;                                        //Line 35
    }                                                 //Line 36
}                                                     //Line 37

