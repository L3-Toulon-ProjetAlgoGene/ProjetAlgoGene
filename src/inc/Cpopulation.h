#ifndef _POP
#define _POP

#include"../inc/Cchemin.h"

typedef Cchemin* ptchemin;

class Cpopulation
  {
  private:
    int taille_pop;
    Cchemin* tab_pop;

  public:
    Cpopulation();
    Cpopulation(ptchemin&, int);
    ~Cpopulation();
    void affiche();
    Cpopulation& operator=(const Cpopulation&);

  };



#endif
