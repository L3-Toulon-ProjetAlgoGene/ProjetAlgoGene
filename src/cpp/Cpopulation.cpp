#include"../inc/Cpopulation.h"
#include"../inc/Cchemin.h"
#include <iostream>

using namespace std;

// fonction pour afficher la population
// void Cpopulation::affiche()
//   {
//   cout<<"taille de la population: "<<taille<<endl;
//   int i;
//   for(i = 0; i < taille; i++)
//     {
//     int j;
//     for(j = 0; j < taille2; j++)
//         cout<<tab_pop[i][j]<<" "<<endl;
//     cout<<"\n"<<endl;
//   }
//   }


Cpopulation::Cpopulation()
  {
  taille_pop = 0;
  tab_pop = 0;
  }

Cpopulation::Cpopulation(ptchemin& a, int nb_chem)
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
  delete [] tab_pop;
  // cout << "destructeur appelé" << endl;
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
