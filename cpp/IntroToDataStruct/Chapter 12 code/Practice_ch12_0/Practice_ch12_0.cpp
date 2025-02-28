    #include <iostream>
    using namespace std;

    class Numbers
    {
    public:
        Numbers(int n);
        void print100s(int n);
        void print10s(int n);
        void print();

    private:
        int num;
        string below20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                            "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                            "eighteen", "nineteen"};
        string twentiesPlus[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        string hundred = "hundred";
        string thousand = "thousand";
    };

    // Testing
    int main()
    {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        Numbers number(n);
        number.print();

        return 0;
    }

    //  Implementation
    Numbers::Numbers(int n)
    {
        num = n;
    }

    void Numbers::print10s(int n)
    {
        
        if (n < 20)
        {
            if (n%10 != 0){
                cout << below20[n];
            }
        }
        else
        {
            cout << twentiesPlus[(n / 10) - 2] << " ";
            if (n % 10 != 0)
            {
                cout << below20[n % 10];
            }
        }
    }

    void Numbers::print100s(int n)
    {
        if (n >= 100)
        {
            cout << below20[n / 100] << " " << hundred << " ";
        }
        print10s(n % 100);
    }

    void Numbers::print()
    {
        if (num >= 1000)
        {
            cout << below20[num / 1000] << " " << thousand << " ";
        }
        print100s(num % 1000);
    }