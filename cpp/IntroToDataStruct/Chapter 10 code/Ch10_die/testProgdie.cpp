//The user program that uses the class die
 
#include <iostream>                                 //Line 1
#include "die.h"                                    //Line 2

using namespace std;                                //Line 3

int main()                                          //Line 4 
{                                                   //Line 5
    die die1;                                       //Line 6
    die die2;                                       //Line 7

    cout << "Line 8: die1: " << die1.getNum()
         << endl;                                   //Line 8
    cout << "Line 9: die2: " << die2.getNum()
         << endl;                                   //Line 9

    die1.roll();                                    //Line 10
    cout << "Line 11: After rolling die1: "
         << die1.getNum() << endl;                  //Line 11

    die2.roll();                                    //Line 12
    cout << "Line 13: After rolling die2: "
         << die2.getNum() << endl;                  //Line 13

    cout << "Line 14: The sum of the numbers rolled"
         << " by the dice is: "
         << die1.getNum() + die2.getNum() << endl;  //Line 14

    die1.roll();                                    //Line 15
    die2.roll();                                    //Line 16

    cout << "Line 17: After again rolling, the sum of "
         << "the numbers rolled is: "
         << die1.getNum() + die2.getNum() << endl;  //Line 17

    return 0;                                       //Line 18
}//end main                                         //Line 19
