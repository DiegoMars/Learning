// Diego Martinez
// Created: Oct 25, 2024

#include <iostream>
using namespace std;

int main()
{
    string inp;
    cout << "Enter two characters: ";
    cin >> inp;
    switch (inp[0]) {
        case 'm':
        case 'M':
            cout << "Mathematics ";
            break;
        case 'c':
        case 'C':
            cout << "Computer Science ";
            break;
        case 'i':
        case 'I':
            cout << "Computer Science ";
            break;
        default:
            cout << "Wrong major code" << endl;     // On code checker, it has it as "wrong" rather than "invalid"
    }
    switch (inp[1]) {
        case '1':
            cout << "Freshman" << endl;
            break;
        case '2':
            cout << "Sophomore" << endl;
            break;
        case '3':
            cout << "Junior" << endl;
            break;
        case '4':
            cout << "Senior" << endl;
            break;
        default:
            cout << "Wrong status code" << endl;    // On code checker, it has it as "wrong" rather than "invalid"
    }

    return 0;
}

// Output
/*
    Enter two characters: M1
    Mathematics Freshman
*/
