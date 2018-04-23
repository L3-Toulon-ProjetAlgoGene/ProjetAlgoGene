#include "../inc/Cselection.h"
#include "../inc/Cpopulation.h"
#include <iostream>

using namespace std;





Cselection::Cselection()
  {

  }

Cchemin Cselection::gettab()
  {
  return nouv_tab;
  }

Cselection::~Cselection()
  {

  }

Cselection::Cselection(Cchemin& a, Cchemin& b)
  {
  int n = a.getNb();
  ptrCville aux;
  aux = new Cville[n];
  int inter = n/2;
  for(int i = 0; i < inter; i++)
    aux[i] = a[i];
  for(int i = inter+1; i < n; i++)
    aux[i] = b[i];
  Cchemin cquetuveux(aux, n);
  nouv_tab = cquetuveux;

  // verification que toutes les villes sont uniques !!!
  }




// ptchemin Cselection::selec_naive(const ptchemin& a, const ptchemin& b, const ptchemin& d)
//   {
//   Cchemin popul;
//   int taille_tab = a->getNb();
//   cout<< taille_tab<< endl;
//   // Attention, il faut une fonction ou une classe pour le tableau de donnees
// //   int taille_donees = d->getNb();
//   popul = remplissage(a, b, taille_tab);
//   doublon(popul, d, taille_tab);
//   }
//


  // methodes
