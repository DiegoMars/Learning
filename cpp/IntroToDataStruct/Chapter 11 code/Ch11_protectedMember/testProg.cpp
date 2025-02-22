//Accessing protected members of a base class in the derived 
//class. 
   
#include <iostream>                                 //Line 1
#include "protectMembClass.h"                       //Line 2
#include "protectMembInDerivedCl.h"                 //Line 3
 
using namespace std;                                //Line 4

int main()                                          //Line 5
{                                                   //Line 6
    bClass bObject;                                 //Line 7

    dClass dObject;                                 //Line 8

    bObject.print();                                //Line 9
    cout << endl;                                   //Line 10

    cout << "*** Derived class object ***" << endl; //Line 11

    dObject.setData('&', 2.5, 7);                   //Line 12

    dObject.print();                                //Line 13

    return 0;                                       //Line 14
}                                                   //Line 15