// Diego Martinez
// Created July 21, 2024
#include <iostream>
using namespace std;

const int N = 3;
void addMatrix(const double a[][N], const double b[][N], double c[][N]);
void addMatrix(const double a[][N], const double b[][N], double c[][N]){
    // Goes through each element and adds them according to their placement
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main(){
    double first[N][N];
    double second[N][N];
    double end[N][N];

    // Grabs all elemnts for the first matrix
    cout << "Enter matrix1: ";
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> first[i][j];
        }
    }

    // Grabs all elemnts for the second matrix
    cout << "Enter matrix2: ";
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> second[i][j];
        }
    }

    addMatrix(first,second,end);

    // Print out results
    cout << "The addition of the matrices is" << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << end[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// Output:
/*
    Enter matrix1: 1
    3
    4.5
    4.5
    4.4
    5.5
    1
    2
    3
    Enter matrix2: 1
    2
    3
    5.5
    5.5
    6
    5
    4
    5
    The addition of the matrices is
    2 5 7.5 
    10 9.9 11.5 
    6 6 8 
*/