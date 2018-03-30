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
    int choix_empl;


  public:
    Cmutation();
    Cmutation(int,int,int);
    int chemin_aleatoire(Cpopulation &);
    int valeur_aleatoire();
    int emplacement_aleatoire(Cchemin &);
    void Affiche();


};



#endif
