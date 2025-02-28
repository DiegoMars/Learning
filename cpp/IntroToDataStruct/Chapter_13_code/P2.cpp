// Write a function template that accepts an argument and returns its absolute value.
// The absolute value of a number is its value with no sign. For example, the absolute
// value of -5 is 5, and the absolute value of 2 is 2. Test the template in a simple driver
// program.
#include <iostream>
using namespace std;

template <class T>
T absValue(T a)
{
    if (a < 0)
    {
        return (a - (a * 2));
    }
    else
    {
        return a;
    }
}

int main()
{
    // Two variables to experiment with...
    int num1 = 10;
    double num2 = -10.5;
    // Try the template with an integer.
    cout << "Absolute value of " << num1
         << " is: " << absValue(num1)
         << endl;
    // Try the template with a double.
    cout << "Absolute value of " << num2
         << " is: " << absValue(num2)
         << endl;

    return 0;
}