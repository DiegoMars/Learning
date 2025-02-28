//Program to illustrate how to use the operators new and delete.
  
#include <iostream>                                    //Line 1
#include <iomanip>                                     //Line 2
 
using namespace std;                                   //Line 3

const double PI = 3.1416;                              //Line 4

int main()                                             //Line 5
{                                                      //Line 6
    double *radiusPtr;                                 //Line 7

    cout << fixed << showpoint << setprecision(2);     //Line 8

    radiusPtr = new double;                            //Line 9

    cout << "Line 10: Enter the radius: ";             //Line 10
    cin >> *radiusPtr;                                 //Line 11
    cout << endl;                                      //Line 12

    cout << "Line 13: Radius = " << *radiusPtr
         << ", area = " << PI * (*radiusPtr) * (*radiusPtr) 
         << endl << endl;                              //Line 13

    cout << "Line 14: Address of radiusPtr: "
         << &radiusPtr << endl;                        //Line 14
    cout << "Line 15: Value stored in radiusPtr: " 
         << radiusPtr << endl;                         //Line 15
    cout << "Line 16: Value stored in the memory "
         << "location to which \n         radiusPtr " 
         << "is pointing: " << *radiusPtr << endl;     //Line 16

    delete radiusPtr;                                  //Line 17

    radiusPtr = new double;                            //Line 18

    *radiusPtr = 5.38;                                 //Line 19

    cout << "Line 20: Address of radiusPtr: "
         << &radiusPtr << endl;                        //Line 20
    cout << "Line 21: Value stored in radiusPtr: " 
         << radiusPtr << endl;                         //Line 21
    cout << "Line 22: Value stored in the memory "
         << "location to which \n         radiusPtr "
        << "is pointing: " << *radiusPtr << endl;      //Line 22

    return 0;                                          //Line 23
}                                                      //Line 24