// Diego Martinez
// 12/15/2024

#include <iostream>
using namespace std;

void reverseDisplay(const string& s) {
    if (s.size() > 0) {
        cout << s[s.size() - 1];
        reverseDisplay(s.substr(0, s.size() - 1));
    }
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;
    reverseDisplay(input);

    return 0;
}

// Output
/*
    Enter a string: abcd
    dcba
*/