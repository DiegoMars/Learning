
#ifndef H_dogTypeVirtual
#define H_dogTypeVirtual
   
#include <string> 
#include "petType.h"

using namespace std;

class dogType: public petType
{
public:
    void print() const;
    void setBreed(string b = "");
    dogType(string n = "", string b = "");

private:
    string breed;
};


#endif