#ifndef _CHEMIN
#define _CHEMIN

#include "../inc/Cville.h"

typedef Cville* ptrCville;

class Cchemin{
private:
  ptrCville chem;
  int nb;
public:
  Cchemin();
  Cchemin(ptrCville&, int);
  ~Cchemin();
  void putVal(Cville, int);
  ptrCville getTab();
  float distance();
  Cchemin& operator=(const Cchemin&);
  Cville operator[](int);
  int getNb();
};

#endif