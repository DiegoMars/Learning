    
#ifndef H_petTypeVirtual
#define H_petTypeVirtual

#include <string> 

using namespace std;

class petType
{
public:
    virtual void print() const;
    petType(string n = "");

private:
    string name;
};


#endif