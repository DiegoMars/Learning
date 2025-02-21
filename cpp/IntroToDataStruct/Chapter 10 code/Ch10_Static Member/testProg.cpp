    
#include <iostream>                             //Line 1

#include "illustrate.h"                         //Line 2

using namespace std;                            //Line 3

int main()                                      //Line 5
{                                               //Line 6
    illustrate illusObject1(3);                 //Line 7
    illustrate illusObject2(5);                 //Line 8

    illustrate::incrementY();                   //Line 9
    illustrate::count++;                        //Line 10
    illusObject1.print();                       //Line 11
    illusObject2.print();                       //Line 12

    cout << "Line 13: ***Increment y using "
         << "illusObject1***" << endl;          //Line 13

    illusObject1.incrementY();                  //Line 14
    illusObject1.setX(8);                       //Line 15
    illusObject1.print();                       //Line 16
    illusObject2.print();                       //Line 17

    cout << "Line 18: ***Increment y using "
         << "illusObject2***" << endl;          //Line 18

    illusObject2.incrementY();                  //Line 19
    illusObject2.setX(23);                      //Line 20
    illusObject1.print();                       //Line 21
    illusObject2.print();                       //Line 22

    return 0;                                   //Line 23
}                                               //Line 24