#include"../inc/Cpopulation.h"
#include"../inc/Cchemin.h"
#include "../inc/Cville.h"
#include "../inc/cng.h"
#include <iostream>

using namespace std;

Cville* tab(){
  static int i = 0;
  Cville* tableau;
  Cville Paris, Marseille;
  if (i == 0) {
    Paris.init();
    Marseille.init();
  }
  tableau = new Cville[2];
  tableau[0] = Paris;
  tableau[1] = Marseille;
  i ++;
  return tableau;
}


void afficher(){
  Cville* tableau;
  Cville Paris, Marseille;
  tableau = tab();
  Paris = tableau[0];
  Marseille = tableau[1];
  cng_put_pixel(Paris.getcoord('x'), Paris.getcoord('y'));
  cng_put_pixel(Marseille.getcoord('x'), Marseille.getcoord('y'));
  cng_current_color(0.1, 0.2, 0.3);
  cng_line(Paris.getcoord('x'), Paris.getcoord('y'), Marseille.getcoord('x'), Marseille.getcoord('y'));
  cng_swap_screen();
}

int main(int argc, char* argv[])
  {
  cng_init_window(&argc, argv, "CNG Test", 1280, 1024);
  cng_display_func(afficher);
  cng_clear_screen();
  cng_main_loop();
  cng_destroy_window();
  return 0;
  }
