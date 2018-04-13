#ifndef _CVILLE
#define _CVILLE

#include <iostream>
using namespace std;

class Cville
{
public:
    Cville();
    void init();
    void putval(float,float);
    int getname();
    float getcoord(char);
    bool operator==(const Cville&);
    friend ostream& operator<<(ostream&, Cville&);
    ~Cville();


private:
    int ville;
    float x;
    float y;


};

#endif
