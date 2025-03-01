// Handle exceptions by fixing the errors. The program 
// continues to prompt the user until a valid input is entered.

#include <iostream>                                 //Line 1
  
using namespace std;                                //Line 2
  
int main()                                          //Line 3
{                                                   //Line 4
    int number;                                     //Line 5
    bool done = false;                              //Line 6

    char str[] = 
          "The input stream is in the fail state."; //Line 7 

    do                                              //Line 8
    {                                               //Line 9
        try                                         //Line 10
        {                                           //Line 11
            cout << "Line 12: Enter an integer: ";  //Line 12
            cin >> number;                          //Line 13
            cout << endl;                           //Line 14
     
            if (!cin)                               //Line 15
                throw str;                          //Line 16

            done = true;                            //Line 17
            cout << "Line 18: Number = " << number 
                 << endl;                           //Line 18
        }                                           //Line 19
        catch (const char messageStr[])             //Line 20
        {                                           //Line 21
            cout << "Line 22: " << messageStr 
                 << endl;                           //Line 22
            cout << "Line 23: Restoring the "
                 << "input stream." << endl;        //Line 23
            cin.clear();                            //Line 24
            cin.ignore(100, '\n');                  //Line 25
        }                                           //Line 26
    }                                               //Line 27
    while (!done);                                  //Line 28

    return 0;                                       //Line 29
}                                                   //Line 30
