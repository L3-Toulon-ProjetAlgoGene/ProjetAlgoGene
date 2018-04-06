#ifndef _MUTATION
#define _MUTATION
#include "Cpopulation.h"
#include "Cchemin.h"
#include <iostream>

using namespace std;

class Cmutation{
  private:
    int new_valeur;
    int choix_chemin;
    int choix_empl1;
    int choix_empl2;

  public:
    Cmutation();
    Cchemin chemin_aleatoire(Cpopulation &);
    //int valeur_aleatoire();
    void emplacement_aleatoire(Cchemin &);
    void Affiche();
    void echange(Cchemin &);
    void Affiche_chemin(Cchemin &);


};



#endif
