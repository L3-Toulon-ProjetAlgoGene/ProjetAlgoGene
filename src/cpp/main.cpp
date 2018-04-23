#include"../inc/Cpopulation.h"
#include"../inc/Cchemin.h"
#include "../inc/Cville.h"
#include "../inc/Cselection.h"
#include "../inc/cng.h"
#include <iostream>
#include <string>
#include <sstream>

#define WSIZE 1280
#define HSIZE 1024

using namespace std;

void menu(void){
  cng_current_color(1.0, 1.0, 1.0);
  cng_draw_string("MENU", 20, 10);
  cng_draw_string("[a] Test avec 2 villes", 20, 50);
  cng_draw_string("[b] Affiche meilleur 1ere gen", 20, 65);
  cng_draw_string("[c] Algo genetique", 20, 80);
  cng_swap_screen();
}

Cville* tab(){
  Cville* tableau;
  Cville Paris, Marseille;
  Paris.init();
  Marseille.init();
  tableau = new Cville[2];
  tableau[0] = Paris;
  tableau[1] = Marseille;
  return tableau;
}

Cville* creeville(int nb){
  Cville* carte;
  carte = new Cville[nb];
  for (int i = 0; i < nb; i++) {
    Cville a;
    a.init();
    carte[i] = a;
  }
  return carte;
}

Cchemin* creechemin(Cville* carte, int tailleville, int nbchem){
  Cchemin* destin;
  destin = new Cchemin[nbchem];
  for (int i = 0; i < nbchem; i++) {
    Cchemin chem(carte, tailleville);
    chem.melange();
    destin[i] = chem;
  }
  return destin;
}

Cpopulation creepremieregeneration(Cville* carte, int nbville){
  int nbchem = 5;
  Cchemin* destin = creechemin(carte, nbville, nbchem);
  Cpopulation peuple(destin, nbchem);
  return peuple;
}

Cchemin meilleurchem(Cpopulation peuple){
   return peuple.getmeilleur();
}


////////////////////////////////////////////////////////////////////


Cpopulation creegenerationsuivante(Cville* carte, int nbville, Cpopulation genpre)
  {
  int nbchem = 5, ind1, ind2;
  Cchemin select, tab1, tab2;
  ind1 = genpre.chemin_alea();
  do {
    ind2 = genpre.chemin_alea();
  } while(ind1 == ind2);
  tab1 = genpre[ind1];
  tab2 = genpre[ind2];
  cout<< "ind1= "<< ind1<< endl;
  cout<< "ind2= "<< ind2<< endl;
  Cselection test(tab1, tab2);
  Cchemin* destin = creechemin(carte, nbville, nbchem);
  Cpopulation peuple(destin, nbchem);
  return peuple;
  }














////////////////////////////////////////////////////////////////////




void afficher(Cville* tableau){
  //  Cville* tableau;
  Cville Paris, Marseille;
  //  tableau = tab();
  Paris = tableau[0];
  Marseille = tableau[1];
  cng_put_pixel(Paris.getcoord('x'), Paris.getcoord('y'));
  cng_put_pixel(Marseille.getcoord('x'), Marseille.getcoord('y'));
  cng_current_color(0.1, 0.2, 0.3);
  cng_line(Paris.getcoord('x'), Paris.getcoord('y'), Marseille.getcoord('x'), Marseille.getcoord('y'));
  cng_swap_screen();
}

int touche_a(void){
  Cville* tableau;
  tableau = tab();
  cng_clear_screen();
  afficher(tableau);
  cng_delay(3000);
  cng_clear_screen();
  menu();
  return 0;
}

int touche_b(void){
  cng_clear_screen();
  Cchemin chem;
  Cpopulation peuple;
  int nb, x1, y1, x2, y2, nbville;
  Cville* carte;
  nbville = 10;
  carte = creeville(nbville);
  peuple = creepremieregeneration(carte, nbville);
  chem = meilleurchem(peuple);
  nb = chem.getNb();
  x1 = chem[0].getcoord('x');
  y1 = chem[0].getcoord('y');
  cng_put_pixel(x1, y1);

  for (int i = 1; i < nb; i++) {
    x2 = chem[i].getcoord('x');
    y2 = chem[i].getcoord('y');
    cng_put_pixel(x2, y2);
    cng_line(x1, y1, x2, y2);
    x1 = x2;
    y1 = y2;
  }
  cng_swap_screen();
  cng_delay(3000);
  cng_clear_screen();
  menu();
  return 0;
}

void affichegen(Cchemin chem ,float meilleurdist, float distmoyenne) {
  int nb, x1, y1, x2, y2;
  string debdist, recup;
  char* affic;
  stringstream ss;
  debdist = "Meilleur distance actuelle : ";
  nb = chem.getNb();
  x1 = chem[0].getcoord('x');
  y1 = chem[0].getcoord('y');
  cng_put_pixel(x1, y1);
  for (int i = 1; i < nb; i++) {
    x2 = chem[i].getcoord('x');
    y2 = chem[i].getcoord('y');
    cng_put_pixel(x2, y2);
    cng_line(x1, y1, x2, y2);
    x1 = x2;
    y1 = y2;
  }
  ss << debdist << meilleurdist;
  recup = ss.str();
  affic = (char*)recup.c_str();
  cng_draw_string(affic, 5, 1000);
  //si on veut la gen x je change le temps du delay jusqu a gen -1 puis gros temps pour gen x par rapport a une touche
  cng_swap_screen();
  cng_delay(3000);
  cng_clear_screen();
}

int touche_c(void){
  cng_clear_screen();
  Cchemin chem;
  Cpopulation peuplepre;
  int nbgen, nbville, dist;
  Cville* carte;
  nbville = 10;
  carte = creeville(nbville);
  peuplepre = creepremieregeneration(carte, nbville);
  nbgen = 49;
  chem = meilleurchem(peuplepre);
  // manque recuperation du fitness moyen
  dist = chem.distance();
  affichegen(chem, dist, 0);
  for (int i = 0; i < nbgen; i++) {
    Cpopulation peuplesuiv;
    peuplesuiv = creegenerationsuivante(carte, nbville, peuplepre);
    chem.~Cchemin();
    Cchemin chem;
    chem = meilleurchem(peuplesuiv);
    dist = chem.distance();
    affichegen(chem, dist, 0);
    peuplepre.~Cpopulation();
    Cpopulation peuplepre;
    peuplepre = peuplesuiv;
    peuplesuiv.~Cpopulation();
  }
  return 0;
}

int main(int argc, char** argv)  {

  cng_init_window(&argc, argv, (char *)"CNG Test", WSIZE, HSIZE);
  cng_display_func(menu);
  cng_assoc_key(cng_a, touche_a);
  cng_assoc_key(cng_b, touche_b);
  cng_assoc_key(cng_c, touche_c);
//  cng_clear_screen();
  cng_main_loop();
  cng_destroy_window();
  return 0;
  }
