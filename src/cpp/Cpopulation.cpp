#include"../inc/Cpopulation.h"
#include"../inc/Cchemin.h"
#include <iostream>

using namespace std;


Cpopulation::Cpopulation()
  {
  taille_pop = 0;
  tab_pop = 0;
  }

Cpopulation::Cpopulation(const ptchemin& a, int nb_chem)
  {
  taille_pop = nb_chem;
  tab_pop = new Cchemin[taille_pop];
  int i;
  for (i = 0; i < taille_pop; i++)
    {
    tab_pop[i] = a[i];
    }
  }

Cpopulation::~Cpopulation()
  {
  // // for (int i = 0; i < taille_pop; i++)
  // //  {
  // //   delete []&tab_pop[i];
  // //  }
  // delete[] tab_pop;
  }

Cpopulation& Cpopulation::operator=(const Cpopulation& e)
  {
  if (this != &e)
    {
    delete [] tab_pop;
    taille_pop = e.taille_pop;
    tab_pop = new Cchemin[taille_pop];
    int i;
    for (i = 0; i < taille_pop; i++)
      {
      tab_pop[i] = e.tab_pop[i];
      }
    }
  return *this;
  }

Cchemin Cpopulation :: operator[](const int i)
    {
    return tab_pop[i];
    }

int Cpopulation::gettaille()
  {
  return taille_pop;
  }

Cchemin Cpopulation::getmeilleur()
  {
  Cchemin meilleur = tab_pop[0];
  for (int i = 1; i < taille_pop; i++)
    {
    if (tab_pop[i].distance() < meilleur.distance())
      {
      meilleur = tab_pop[i];
      }
    }
  return meilleur;
  }
