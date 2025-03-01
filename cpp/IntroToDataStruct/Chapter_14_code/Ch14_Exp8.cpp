// Handling out_of_range and length_error exceptions.

#include <iostream>                                  //Line 1
#include <string>                                    //Line 2
   
using namespace std;                                 //Line 3

int main()                                           //Line 4
{                                                    //Line 5
    string sentence;                                 //Line 6
    string str1, str2, str3;                         //Line 7

    try                                              //Line 8
    {                                                //Line 9
        sentence = "Testing string exceptions!";     //Line 10
        cout << "Line 11: sentence = " << sentence 
             << endl;                                //Line 11
        cout << "Line 12: sentence.length() = " 
             << static_cast<int>(sentence.length())
             << endl;                                //Line 12

        str1 = sentence.substr(8, 20);               //Line 13
        cout << "Line 14: str1 = " << str1 << endl;  //Line 14

        str2 = sentence.substr(28, 10);              //Line 15
        cout << "Line 16: str2 = " << str2 << endl;  //Line 16

        str3 = "Exception handling. " + sentence;    //Line 17
        cout << "Line 18: str3 = " << str3 << endl;  //Line 18

    }                                                //Line 19
    catch (out_of_range re)                          //Line 20
    {                                                //Line 21
        cout << "Line 22: In the out_of_range catch" 
             << " block: " << re.what() << endl;     //Line 22
    }                                                //Line 23
    catch (length_error le)                          //Line 24
    {                                                //Line 25
        cout << "Line 26: In the length_error catch"
             << " block: " << le.what() << endl;     //Line 26
    }                                                //Line 27

    return 0;                                        //Line 28
}                                                    //Line 29
