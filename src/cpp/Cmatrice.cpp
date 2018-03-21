#include "../inc/Cmatrice.h"
#include <iostream>
#include <cmath>

using namespace std;

Cmatrice :: Cmatrice(){
  matrice = 0;
}

Cmatrice :: Cmatrice(int nbville, Cville* tab){
  int x1, y1, x2, y2, xcar, ycar;
  taille = nbville;
  matrice = new float*[taille];
  for (int i = 0; i < taille; i++) {
    matrice[i] = new float[taille];
  }
  for (int j = 0; j < taille; j++) {
    x1 = tab[j].getcoord('x');
    y1 = tab[j].getcoord('y');
    for (int k = 0; k < taille; k++) {
      x2 = tab[k].getcoord('x');
      y2 = tab[k].getcoord('y');
      xcar = (x2 - x1) * (x2 - x1);
      ycar = (y2 - y1) * (y2 - y1);
      matrice[j][k] = sqrt(xcar + ycar);
    }
  }
}

Cmatrice :: ~Cmatrice(){
  for (int i = 0; i < taille; i++) {
    delete[] matrice[i];
  }
  delete[] matrice;
}

Cmatrice& Cmatrice :: operator=(const Cmatrice& M){
  if (this != &M){
    for (int i = 0; i < taille; i++) {
      delete[] matrice[i];
    }
    delete[] matrice;
    taille = M.taille;
    matrice = new float*[taille];
    for (int j = 0; j < taille; j++) {
      matrice[j] = new float[taille];
    }
    for (int k = 0; k < taille; k++) {
      for (int l = 0; l < taille; l++) {
        matrice[k][l] = M.matrice[k][l];
      }
    }
  }
  return *this;
}

void Cmatrice :: Affiche(){
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      cout << matrice[i][j] << " ";
    }
    cout << endl;
  }
}

float Cmatrice :: GetDistance(int i, int j){
  return matrice[i][j];
}
