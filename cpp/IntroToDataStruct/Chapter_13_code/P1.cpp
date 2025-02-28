// Write templates for the two functions minimum and maximum . The minimum function
// should accept two arguments and return the value of the argument that is the lesser
// of the two. The maximum function should accept two arguments and return the value
// of the argument that is the greater of the two. Design a simple driver program that
// demonstrates the templates with various data types.

#include<iostream>
using namespace std;

template <class T>
T minimum(T a, T b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}
template <class T>
T maximum(T a, T b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

int main(){
    // Test with int arguments.
    int num1 = 5;
    int num2 = 3;
    cout << "minimum of 5, 3 is: " ;
    cout << minimum(num1, num2) << endl;
    cout << "maximum of 5, 3 is: " ;
    cout << maximum(num1, num2) << endl;

    // Test with double arguments.
    double num3 = 5.5;
    double num4 = 3.5;
    cout << "minimum of 5.5, 3.5 is: " ;
    cout << minimum(num3, num4) << endl;
    cout << "maximum of 5.5, 3.5 is: " ;
    cout << maximum(num3, num4) << endl;
    
    // Test with string arguments.
    string hello = "hello";
    string hi = "hi";
    cout << "minimum of \"hello\" and \"hi\" is: ";
    cout << minimum(hello, hi) << endl;
    cout << "maximum of \"hello\" and \"hi\" is: ";
    cout << maximum(hello, hi) << endl;

    return 0;
}