#include"../inc/Cpopulation.h"
#include"../inc/Cchemin.h"
#include "../inc/Cville.h"
#include "../inc/cng.h"
#include <iostream>

#define WSIZE 1280
#define HSIZE 1024

using namespace std;

void menu(void){
  cng_current_color(1.0, 1.0, 1.0);
  cng_draw_string("MENU", 20, 10);
  cng_draw_string("[a] Test avec 2 villes", 20, 50);
  cng_draw_string("[b] Affiche meilleur 1ere gen", 20, 65);
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

Cpopulation creepremieregeneration(void){
  int nbville = 10, nbchem = 5;
  Cville* carte = creeville(nbville);
  Cchemin* destin = creechemin(carte, nbville, nbchem);
  Cpopulation peuple(destin, nbchem);
  return peuple;
}

Cchemin meilleurchem(Cpopulation peuple){
   return peuple.getmeilleur();
}

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
  int nb, x1, y1, x2, y2;
  peuple = creepremieregeneration();
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

int main(int argc, char** argv)  {

  cng_init_window(&argc, argv, (char *)"CNG Test", WSIZE, HSIZE);
  cng_display_func(menu);
  cng_assoc_key(cng_a, touche_a);
  cng_assoc_key(cng_b, touche_b);
//  cng_clear_screen();
  cng_main_loop();
  cng_destroy_window();
  return 0;
  }
