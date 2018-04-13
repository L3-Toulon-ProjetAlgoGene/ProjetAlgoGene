#ifndef _CHEMIN
#define _CHEMIN

#include "../inc/Cville.h"
#include <iostream>

using namespace std;

typedef Cville* ptrCville;

class Cchemin{
private:
  ptrCville chem;
  int nb;
public:
  Cchemin();
  Cchemin(const ptrCville&, int);
  ~Cchemin();
  void putVal(Cville, int);
  ptrCville getTab();
  float distance();
  Cchemin& operator=(const Cchemin&);
  Cville operator[](int);
  int getNb();
  Cchemin& melange();
  friend ostream& operator<<(ostream&, const Cchemin&);
};

#endif
