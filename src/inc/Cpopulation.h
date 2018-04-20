#ifndef _POP
#define _POP

#include"../inc/Cchemin.h"

typedef Cchemin* ptchemin;

class Cpopulation
  {
  private:
    int taille_pop;
    ptchemin tab_pop;

  public:
    Cpopulation();
    Cpopulation(const ptchemin&, int);
    // ~Cpopulation();
    void affiche();
    Cpopulation& operator=(const Cpopulation&);
    Cchemin operator[](const int);
    int gettaille();
    Cchemin getmeilleur();

  };



#endif
