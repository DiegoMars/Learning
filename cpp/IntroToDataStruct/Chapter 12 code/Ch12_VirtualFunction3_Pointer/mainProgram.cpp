   
#include <iostream>                 
#include "petType.h"
#include "dogType.h"

using namespace std;
 
void callPrint(petType *p);

int main()                                       //Line 1
{                                                //Line 2
    petType *q;                                  //Line 3
    dogType *r;                                  //Line 4

    q = new petType("Lucky");                    //Line 5
    r = new dogType("Tommy", "German Shepherd"); //Line 6

    q->print();                                  //Line 7
    cout << endl;                                //Line 8
    r->print();                                  //Line 9 

    cout << "*** Calling the function callPrint  ***"
         << endl;                                //Line 10
    callPrint(q);                                //Line 11
    cout << endl;                                //Line 12
    callPrint(r);                                //Line 13

    return 0;                                    //Line 14
}                                                //Line 15

void callPrint(petType *p)
{
    p->print();
}

