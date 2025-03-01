//The user program that uses the class circleType
  
#include <iostream>                                     //Line 1
#include <iomanip>                                      //Line 2
#include "circleType.h"                                 //Line 3
#include "negativeNumber.h"                             //Line 4
 
using namespace std;                                    //Line 5

int main()                                              //Line 6
{                                                       //Line 7
    circleType circle;                                  //Line 8

    double radius;                                      //Line 9

    cout << fixed << showpoint << setprecision(2);      //Line 10

    try                                                 //Line 11
    {                                                   //Line 12
        cout << "Line 13: Enter the radius "
             << "of a circle: ";                        //Line 13
        cin >> radius;                                  //Line 14
        cout << endl;                                   //Line 15

        circle.setRadius(radius);                       //Line 16

        cout << "Line 17: circle - "
             << "radius: " << circle.getRadius()
             << ", area: " << circle.area()
             << ", circumference: " 
             << circle.circumference() << endl;         //Line 17
    }                                                   //Line 18
    catch (negativeNumber obj)                          //Line 19
    {                                                   //Line 20
        cout << "Line 21: " << obj.what() << endl;      //Line 21
    }                                                   //Line 22

    return 0;                                           //Line 23
}//end main                                             //Line 24
