#include "../inc/Cselection.h"
#include "../inc/Cpopulation.h"
#include "../inc/Cchemin.h"
#include <iostream>



Cselection::Cselection()
  {
  tab = 0;
  }


Cselection::Cselection(ptchemin& a, ptchemin& b)
  {
  //int n = // recuperer la taille d'un chemin
  tab = new Cchemin[n];
  for(int i = 0; i < n; i++)
    tab[i] = a[i];
  for(int i = n; i < taille; i++)
    tab[i] = b[i];
  // verification que toutes les villes sont uniques !!!
  }

Cselection::~Cselection()
  {
  delete tab[];
  }

// ptchemin& ptchemin::operator=(const ptchemin& a)
//   {
//   if(*this != a)
//     {
//
//     }
//   return(*this);
//   }
