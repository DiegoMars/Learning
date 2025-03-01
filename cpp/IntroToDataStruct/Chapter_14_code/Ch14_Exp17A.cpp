// Handle exceptions by fixing the errors. The program 
// continues to prompt the user until a valid input is entered.

#include <iostream>                                 //Line 1
#include <string>                                   //Line 2
  
using namespace std;                                //Line 3
  
int main()                                          //Line 4
{                                                   //Line 5
    int number;                                     //Line 6
    bool done = false;                              //Line 7

    int x = 90;

    char str[] = 
          "The input stream"; //Line 8 

    do                                              //Line 9
    {                                               //Line 10
        try                                         //Line 11
        {                                           //Line 12
            cout << "Line 13: Enter an integer: ";  //Line 13
            cin >> number;                          //Line 14
            cout << endl;                           //Line 15

            cout << "********: " << str << endl;
     
            if (!cin)                               //Line 16
                throw str;                          //Line 17

            done = true;                            //Line 18
            cout << "Line 19: Number = " << number 
                 << endl;                           //Line 19
        }                                           //Line 20
        catch (const char messageStr[])                   //Line 21
        {                                           //Line 22
            cout << "Line 23: " << messageStr 
                 << endl;                           //Line 23
            cout << "Line 24: Restoring the "
                 << "input stream." << endl;        //Line 24
            cin.clear();                            //Line 25
            cin.ignore(100, '\n');                  //Line 26
        }                                           //Line 27
    }                                               //Line 28
    while (!done);                                  //Line 29

    return 0;                                       //Line 30
}                                                   //Line 31
