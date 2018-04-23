#include "../inc/Cselection.h"
#include "../inc/Cpopulation.h"
#include <iostream>

using namespace std;





Cselection::Cselection()
  {

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

// Cchemin remplissage(Cchemin t1, Cchemin t2, int nb)
//   {
//   Cville* t = new Cville[nb];
//   int fin1 = nb/2;
//   for(int i = 0; i < fin1; i++)
//     t[i] = t1[i];
//   // cout<< "tb11= ";
//   // for(int i = 0; i < fin1; i++)
//   //   cout<< t[i].getname()<< " ";
//   // cout<< endl;
//
//   for(int i = fin1; i < nb; i++)
//     t[i] = t2[i];
//
//   // cout<< "tb22= ";
//   // for(int i = fin1; i < nb; i++)
//   //   cout<< t[i].getname()<< " ";
//   // cout<< endl;
//
//   Cchemin tableau(t, nb);
//   return tableau;
//   }


// void verif(Cchemin t, int ind, Cchemin d, int n)
//   {
//   bool verifi;
//   // i: indice pour parcourir lentement chaque element de d
//   for(int i = 0; i < n; i++)
//     {
//     verifi = 0;
//     for(int j = 0; j < n; j++)
//       if(d[i] == t[j])
//         verifi = 1;
//     if(verifi == 0)
//       t[ind] = d[i];
//     }
//   }


// void doublons(Cchemin t, Cchemin d, int nb)
//   {
//   // comme les tableaux t1 et t2 sont deja prives de doublons, il ne peut pas
//   // y en avoir dans la deuxieme partie du tableau (ni dans la premiere)
//   int n = nb/2;
//   // boucle pour parcourir le tableau et s'arreter sur chaque element
//   for(int i = 0; i < n; i++)
//     for(int j = 0; j < n; j++)
//       if(t[i] == t[j])
//         verif(t, i, d, nb);

        // cout<< i<< " "<< t[i]<< " "<< j<< " "<< t[j]<< endl;
  // }
