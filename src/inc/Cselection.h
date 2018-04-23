#ifndef _SEL
#define _SEL

#include"../inc/Cpopulation.h"

typedef Cchemin* ptchemin;

class Cselection
  {
  private:
    Cchemin nouv_tab;
  public:
    Cselection();
    Cselection(Cchemin&, Cchemin&);
    ~Cselection();
    Cchemin gettab();
    // ptchemin& operator=(const ptchemin&);
    // ptchemin selec_naive(const ptchemin&, const ptchemin&, const ptchemin&);

    // methodes
    // Cchemin remplissage(Cchemin, Cchemin, int);
    // void verif(Cchemin, int, Cchemin, int); //le 2eme Cchemin est le tab de donnees attention a changer ça
    // void doublons(Cchemin, Cchemin, int); //le 2eme Cchemin est le tab de donnees attention a changer ça


  };



#endif
