#include "../inc/Cchemin.h"
#include "../inc/Cville.h"
#include <cmath>
#include <cstdlib>
#include <time.h>

Cchemin :: Cchemin(){
  nb = 0;
  chem = 0;
}

Cchemin :: Cchemin(const ptrCville& v, int nombre){
  nb = nombre;
  chem = new Cville[nb];
  for (int i = 0; i < nb; i++) {
    chem[i] = v[i];
  }
}

Cchemin :: ~Cchemin(){

}

void Cchemin :: putVal(Cville v, int i){
  chem[i] = v;
}

ptrCville Cchemin :: getTab(){
  return chem;
}

float Cchemin :: distance(){
  float dist = 0, x1, x2, y1, y2, xcar, ycar;
  for (int i = 0; i < nb - 1; i++) {
    x1 = chem[i].getcoord('x');
    y1 = chem[i].getcoord('y');
    x2 = chem[i + 1].getcoord('x');
    y2 = chem[i + 1].getcoord('y');
    xcar = (x2 - x1) * (x2 - x1);
    ycar = (y2 - y1) * (y2 - y1);
    dist += sqrt(xcar + ycar);
  }
  return dist;
}

Cchemin& Cchemin :: operator=(const Cchemin& C){
  if (this != &C) {
    delete[] chem;
    nb = C.nb;
    chem = new Cville[nb];
    for (int i = 0; i < nb; i++) {
      chem[i] = C.chem[i];
    }
  }
  return *this;
}

Cville Cchemin :: operator[](int i){
  return chem[i];
}

int Cchemin :: getNb(){
  return nb;
}

Cchemin& Cchemin::melange()
  {
  srand(time(NULL));
  int a = 0;
  int b = 0;
  Cville inter;
  int nb_chang = (rand() % 50) + 1;
  for (int i = 0; i < nb_chang; i++)
    {
    do {
      a = rand()%nb;
      b = rand()%nb;
    } while(a == b);
    inter = chem[a];
    chem[a] = chem[b];
    chem[b] = inter;
    }
  return *this;
  }

ostream& operator<<(ostream& o, const Cchemin& C){
  o << "Nb ville dans le chemin : " << C.nb << endl;
  o << "adresse du chemin: "<< &C<< endl;
  for (int i = 0; i < C.nb; i++) {
    o << "chem["<< i<< "]"<< C.chem[i] << endl;
  }
  return o;
}
