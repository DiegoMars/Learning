// Write a recursive algorithm to multiply two positive integers m and n using
// repeated addition. Specify the base case and the recursive case. (2, 3, 4, 6)
#include<iostream>
using namespace std;

int sumOfNums(int m, int n){
    if (n != 0){
        return(m + sumOfNums(m, n-1));
    }
    int rThis = 0;
    return rThis;
}

int main(){
    int m = 2;
    int n = 30;
    int sum = sumOfNums(m, n);
    cout << sum << endl;

    return 0;
}