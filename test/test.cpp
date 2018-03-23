


/*
tab1: tableau sur lequel on prend que la fin
tab2: tableau qui contient le debut deja traite
donnees: tableau qui contient la liste des villes a traiter
*/
int parcours(tab1, tab2, donnees, ind)
  {
  int a = len(tab1);
  int b = len(tab2);
  int c = len(donnees);
  for(int i = 0; i < ind; i++)
    {
    for(int j = 0; j < c; j++)
      {
      if(donnees[j] == tab2[])

      }
    }

  }







int main(void)
  {
  int n = 10;
  int m = 10;
  int donnees[n] = {0,1,2,3,4,5,6,7,8,9};
  int tab[n] = {0,1,2,3,4,5,6,7,8,9};
  int tab2[m] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int t[n];

  for(int i = 0; i < n/2; i++)
    {
    t[i] = tab[i];
    }

  for(int i = n/2; i < n; i++ )
    {
    for(int j = 0; j < n/2; j++)
      {
      if(t[j] == tab2[i])
        for(int k = 0; k < n; k++)
          {

          }
      }
    }






  return 0;
  }
