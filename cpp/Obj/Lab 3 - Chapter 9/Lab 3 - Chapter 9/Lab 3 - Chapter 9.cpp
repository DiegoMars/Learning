// Diego Martinez
// Created: Nov 10, 2024
#include <iostream>
using namespace std;

class EvenNumber {
private:
    int value;
public:
    // Constructors
    EvenNumber() {
        int value = 0;
    }
    EvenNumber(int v) {
        if (v % 2 == 0) {
            value = v;
        }
        else {
            value = ++v;
        }
    }

    // Functions
    int getValue() {
        return value;
    }
    EvenNumber getNext() {
        EvenNumber nextThing(value + 2);
        return nextThing;
    }
    EvenNumber getPrevious() {
        EvenNumber lastThing(value - 2);
        return lastThing;
    }
};

int main(){
    EvenNumber num1(16);
    EvenNumber nextNum1 = num1.getNext();
    EvenNumber lastNum1 = num1.getPrevious();
    cout << nextNum1.getValue() << endl;
    cout << lastNum1.getValue() << endl;
    cout << "\n";

    EvenNumber num2(5);
    EvenNumber nextNum2 = num2.getNext();
    EvenNumber lastNum2 = num2.getPrevious();
    cout << nextNum2.getValue() << endl;
    cout << lastNum2.getValue() << endl;

    return 0;
}

// Output
/*
    18
    14

    8
    4
*/