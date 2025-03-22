#include <iostream>                                 //Line 1
#include "searchSortAlgorithms.h"                   //Line 2
   
using namespace std;                                //Line 3
 
template <class elemType>                           //Line 4
void print(elemType list[], int length);            //Line 5
 
int main()                                          //Line 6
{                                                   //Line 7
    int intList[] = {2, 56, 34, 25, 73, 
                     46, 89, 10, 5, 16};            //Line 8

    cout << "Line 9: Before sorting, intList: ";    //Line 9

    print(intList, 10);                             //Line 10

    cout << endl;                                   //Line 11

    bubbleSort(intList, 10);                        //Line 12

    cout << "Line 13: After sorting, intList: ";    //Line 13

    print(intList, 10);                             //Line 14

    return 0;                                       //Line 15
}                                                   //Line 16

template <class elemType>                           //Line 17
void print(elemType list[], int length)             //Line 18
{                                                   //Line 19
    for (int i = 0; i < length; i++)                //Line 20
        cout << list[i] << " ";                     //Line 21

    cout << endl;                                   //Line 22
}                                                   //Line 23
