// Handling bad_alloc exception thrown by the operator new.

#include <iostream>                                 //Line 1
  
using namespace std;                                //Line 2
 
int main()                                          //Line 3
{                                                   //Line 4
    int *list[100];                                 //Line 5

    try                                             //Line 6
    {                                               //Line 7
        for (int i = 0; i < 100; i++)               //Line 8
        {                                           //Line 9
            list[i] = new int[50000000];            //Line 10
            cout << "Line 11: Created list[" << i 
                 << "] of 50000000 components." 
                 << endl;                           //Line 11
        }                                           //Line 12
    }                                               //Line 13
    catch (bad_alloc be)                            //Line 14
    {                                               //Line 15
        cout << "Line 16: In the bad_alloc catch "
              << "block: " << be.what() << "."
              << endl;                              //Line 16
    }                                               //Line 17

    return 0;                                       //Line 18
}                                                   //Line 19
