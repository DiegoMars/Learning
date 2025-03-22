#include <iostream>                             //Line 1
#include "searchSortAlgorithms.h"               //Line 2
   
using namespace std;                            //Line 3
  
int main()                                      //Line 4
{                                               //Line 5
    int intList[] = {2, 16, 34, 45, 53, 
                     56, 69, 70, 75, 96};       //Line 6

    int pos;                                    //Line 7

    pos = binarySearch(intList, 10, 45);        //Line 8

    if (pos != -1)                              //Line 9
        cout << "Line 10: " << 45 << " found "
             << "at position " << pos << endl;  //Line 10
    else                                        //Line 11
        cout << "Line 12: " << 45 
             << " is not in intList " << endl;  //Line 12

    return 0;                                   //Line 13
}                                               //Line 14
