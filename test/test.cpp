#include <iostream>

using namespace std;


/*
tab1: tableau sur lequel on prend que la fin
tab2: tableau qui contient le debut deja traite
donnees: tableau qui contient la liste des villes a traiter
*/

// fonction pour initialiser le premier tableau

int* init_tab1(int nb)
  {
  int *tab = new int [nb];
  for (int i = 0; i < nb; i++)
    tab[i] = i;
  return tab;
  }


int* init_tab2(int nb)
  {
  int* tab = new int[nb];
  int j = nb - 1;
  for(int i = 0; i < nb; i++)
    {
    tab[i] = j;
    j--;
    }
  return tab;
  }

int* rmpls(int* tab1, int* tab2, int nb)
  {
  int* t = new int[nb];
  int fin1 = nb/2;
  for(int i = 0; i < fin1; i++)
    t[i] = tab1[i];
  cout<< "tb11= ";
  for(int i = 0; i < fin1; i++)
    cout<< t[i]<< " ";
  cout<< endl;

  for(int i = fin1; i < nb; i++)
    t[i] = tab2[i];

  cout<< "tb22= ";
  for(int i = fin1; i < nb; i++)
    cout<< t[i]<< " ";
  cout<< endl;

  return t;
  }


void verif(int* t, int ind, int* d, int n)
  {
  bool verifi;
  // i: indice pour parcourir lentement chaque element de d
  for(int i = 0; i < n; i++)
    {
    verifi = 0;
    for(int j = 0; j < n; j++)
      if(d[i] == t[j])
        verifi = 1;
    if(verifi == 0)
      t[ind] = d[i];
    }
  }

void doublons(int* t, int* d, int nb)
  {
  // comme les tableaux t1 et t2 sont deja prives de doublons, il ne peut pas
  // y en avoir dans la deuxieme partie du tableau (ni dans la premiere)
  int n = nb/2;
  // boucle pour parcourir le tableau et s'arreter sur chaque element
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(t[i] == t[j])
        verif(t, i, d, nb);

        // cout<< i<< " "<< t[i]<< " "<< j<< " "<< t[j]<< endl;
  }





int main(void)
  {
  int n = 10;
  int m = 10;

  // premier tableau
  int* tb1 = init_tab1(n);
  int* donnees = init_tab1(n);

  cout<< "tb1= ";
  for (int i = 0; i < n; i++)
    cout<< tb1[i]<< " ";
  cout<< endl;

  // deuxième tableau
  int* tb2 = init_tab2(n);

  cout<< "tb2= ";
  for (int i = 0; i < n; i++)
    cout<< tb2[i]<< " ";
  cout<< endl;

  // fonction de remplissage
  int* tb = rmpls(tb1, tb2, n);
  cout<< "tb= ";
  for (int i = 0; i < n; i++)
    cout<< tb[i]<< " ";
  cout<< endl;

  doublons(tb, donnees, n);
  cout<< "tbfin= ";
  for (int i = 0; i < n; i++)
    cout<< tb[i]<< " ";
  cout<< endl;

  return 0;
  }
