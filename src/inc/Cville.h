#ifndef _CVILLE
#define _CVILLE

class Cville
{
public:
    Cville();
    void init();
    void putval(float,float);
    int getname();
    float getcoord(char);
    ~Cville();


private:
    int ville;
    float x;
    float y;


};

#endif
