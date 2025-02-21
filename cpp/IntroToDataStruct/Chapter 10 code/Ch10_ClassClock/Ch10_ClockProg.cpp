//The complete program listing of the program that defines 
//and uses the class clockType
   
#include <iostream>  
using namespace std; 

class clockType
{
public:
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const;

private:
    int hr;
    int min;
    int sec;
};

int main()                                             //Line 1
{                                                      //Line 2
    clockType myClock;                                 //Line 3
    clockType yourClock;                               //Line 4

    int hours;                                         //Line 5
    int minutes;                                       //Line 6
    int seconds;                                       //Line 7

        //Set the time of myClock
    myClock.setTime(5, 4, 30);                         //Line 8

    cout << "Line 9: myClock: ";                       //Line 9
    myClock.printTime();  //print the time of myClock    Line 10
    cout << endl;                                      //Line 11

    cout << "Line 12: yourClock: ";                    //Line 12
    yourClock.printTime(); //print the time of yourClock Line 13
    cout << endl;                                      //Line 14

        //Set the time of yourClock
    yourClock.setTime(5, 45, 16);                      //Line 15

    cout << "Line 16: After setting, yourClock: ";     //Line 16
    yourClock.printTime(); //print the time of yourClock Line 17
    cout << endl;                                      //Line 18

        //Compare myClock and yourClock
    if (myClock.equalTime(yourClock))                  //Line 19
        cout << "Line 20: Both times are equal."
             << endl;                                  //Line 20
    else                                               //Line 21
        cout << "Line 22: The two times are not equal."
             << endl;                                  //Line 22

    cout << "Line 23: Enter the hours, minutes, and "
         << "seconds: ";                               //Line 23
    cin >> hours >> minutes >> seconds;                //Line 24
    cout << endl;                                      //Line 25

        //Set the time of myClock using the value of the
        //variables hours, minutes, and seconds
    myClock.setTime(hours, minutes, seconds);          //Line 26

    cout << "Line 27: New myClock: ";                  //Line 27
    myClock.printTime();   //print the time of myClock   Line 28
    cout << endl;                                      //Line 29

        //Increment the time of myClock by one second
    myClock.incrementSeconds();                        //Line 30

    cout << "Line 31: After incrementing myClock by " 
         << "one second, myClock: ";                   //Line 31
    myClock.printTime();   //print the time of myClock   Line 32
    cout << endl;                                      //Line 33

        //Retrieve the hours, minutes, and seconds of the 
        //object myClock
    myClock.getTime(hours, minutes, seconds);          //Line 34

        //Output the value of hours, minutes, and seconds
    cout << "Line 35: hours = " << hours 
         << ", minutes = " << minutes 
         << ", seconds = " << seconds << endl;         //Line 35

    return 0;                                          //Line 36
}//end main                                              Line 37

void clockType::setTime(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else 
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else 
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else 
        sec = 0;
}

void clockType::getTime(int& hours, int& minutes, 
                        int& seconds) const
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::incrementHours()
{
    hr++;
    if (hr > 23)
        hr = 0;
}

void clockType::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours(); //increment hours
    }
}

void clockType::incrementSeconds()
{
    sec++;

    if (sec > 59)
    {
        sec = 0;
        incrementMinutes(); //increment minutes
    }
}

void clockType::printTime() const
{
    if (hr < 10)
        cout << "0";
    cout << hr << ":";

    if (min < 10)
        cout << "0";
    cout << min << ":";

    if (sec < 10)
        cout << "0";
    cout << sec;
}

bool clockType::equalTime(const clockType& otherClock) const
{
    return (hr == otherClock.hr 
            && min == otherClock.min 
            && sec == otherClock.sec);
}
