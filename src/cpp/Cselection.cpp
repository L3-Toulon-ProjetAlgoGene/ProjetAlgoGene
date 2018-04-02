#include "../inc/Cselection.h"
#include "../inc/Cpopulation.h"
#include <iostream>

using namespace std;

Cselection::Cselection()
  {
  tab;
  }


Cselection::Cselection(ptchemin& a, ptchemin& b)
  {
  // attention si tab est impair !!
  int n = a[0].getNb();
  ptrCville* aux;
  aux = new ptrCville[n];
  int inter = n/2;

  for(int i = 0; i < inter; i++)
    aux[i] = a[i].getTab();
  for(int i = inter+1; i < n; i++)
    aux[i] = b[i].getTab();

  // verification que toutes les villes sont uniques !!!
  }


ptchemin Cselection::selec_naive(const ptchemin& a, const ptchemin& b, const ptchemin& d)
  {
  int taille_tab = a->getNb();
  cout<< taille_tab<< endl;
  // Attention, il faut une fonction ou une classe pour le tableau de donnees
  int taille_donees = d->getNb();
  }




























// Cselection::~Cselection()
//   {
//   delete tab[];
//   }

// ptchemin& ptchemin::operator=(const ptchemin& a)
//   {
//   if(*this != a)
//     {
//
//     }
//   return(*this);
//   }
