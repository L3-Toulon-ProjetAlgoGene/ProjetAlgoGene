#ifndef _SEL
#define _SEL

#include"../inc/Cchemin.h"

typedef Cchemin* ptchemin;

class Cselection
  {
  private:
    Cchemin tab;
  public:
    Cselection();
    Cselection(ptchemin&, ptchemin&);
    ~Cselection();
    // ptchemin& operator=(const ptchemin&);
    ptchemin selec_naive(const ptchemin&, const ptchemin&, const ptchemin&);

    // methodes
    Cchemin remplissage(Cchemin, Cchemin, int);
    void verif(Cchemin, int, Cchemin, int); //le 2eme Cchemin est le tab de donnees attention a changer ça
    void doublons(Cchemin, Cchemin, int); //le 2eme Cchemin est le tab de donnees attention a changer ça


  };



#endif
