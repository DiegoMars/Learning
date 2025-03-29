#include <iostream>
#include "binarySearchStuff/binarySearchTree.h"
#include "queueStuff/linkedQueue.h"
using namespace std;

int main()
{
    bSearchTreeType<int> treeRoot;
    int num;

    cout << "Line 10: Enter numbers ending with -999." << endl;
    cin >> num;

    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }

    

    return 0;
}

// Test input:
// 12 5 6 7 90 40 30 20 23 1 -999