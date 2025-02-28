//Test Program for classExample
    
#include <iostream>             //Line 1
#include "classExample.h"       //Line 2
  
using namespace std;            //Line 3
 
int main()                      //Line 4
{                               //Line 5
    classExample *cExpPtr;      //Line 6
    classExample cExpObject;    //Line 7

    cExpPtr = &cExpObject;      //Line 8

    cExpPtr->setX(5);           //Line 9
    cExpPtr->print();           //Line 10

    return 0;                   //Line 11
}                               //Line 12