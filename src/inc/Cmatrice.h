#ifndef _CMATRICE
#define _CMATRICE

#include "Cville.h"

class Cmatrice{
private:
  int taille;
  float** matrice;
public:
  Cmatrice();
  Cmatrice(int, Cville*); //tableau de ville pour parcourir chaque ville
  ~Cmatrice();
  Cmatrice& operator=(const Cmatrice&);
  void Affiche();
  //indice des villes concernées(donnée par le tableau Cville* du dessus)
  float GetDistance(int, int);
};

#endif
