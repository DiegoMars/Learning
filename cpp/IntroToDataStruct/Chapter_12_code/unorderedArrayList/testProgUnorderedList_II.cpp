
//Program to test the copy constructor of the class
//arrayListType and unorderedArrayListType

#include <iostream>                                 //Line 1
#include "unorderedArrayListType.h"                 //Line 2
  
using namespace std;                                //Line 3

void testCopyConstructor
       (unorderedArrayListType testList);           //Line 4

int main()                                          //Line 5
{                                                   //Line 6
    unorderedArrayListType intList(25);             //Line 7

    int number;                                     //Line 8

    cout << "List 9: Enter 8 integers: ";           //Line 9

    for (int count = 0; count < 8; count++)         //Line 10
    {                                               //Line 11
        cin >> number;                              //Line 12
        intList.insertEnd(number);                  //Line 13
    }                                               //Line 14

    cout << endl;                                   //Line 15

    cout << "Line 16: intList: ";                   //Line 16
    intList.print();                                //Line 17
    cout << endl;                                   //Line 18

        //test copy constructor
	testCopyConstructor(intList);                   //Line 19

	cout << "Line 20: intList after the copy "
         << "constructor: ";                        //Line 20
	intList.print();                                //Line 21
    cout << endl;                                   //Line 22

        //Create temp and initialize it using intList
    unorderedArrayListType temp(intList);           //Line 23

    cout << "Line 24: temp: ";                      //Line 24
    temp.print();                                   //Line 25
    cout << endl;                                   //Line 26

       //Replace the first element of temp.
    temp.replaceAt(0, -75);                         //Line 27

    cout << "Line 28: After replacing the first "
         << "element, temp: ";                      //Line 28
    temp.print();                                   //Line 29
    cout << endl;                                   //Line 30

    cout << "Line 31: intList: ";                   //Line 31
    intList.print();                                //Line 32
    cout << endl;                                   //Line 33

	return 0;                                       //Line 34
}                                                   //Line 35

void testCopyConstructor(unorderedArrayListType testList)
{
      //This function first creates and then destroys
      //testList.
}

