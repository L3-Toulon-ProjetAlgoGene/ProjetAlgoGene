#include"../inc/Cpopulation.h"
#include"../inc/Cchemin.h"
#include "../inc/Cville.h"
#include "../inc/cng.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
  {
  Cville Paris, Marseille;
  Paris.init();
  Marseille.init();
  cng_init_window(&argc, argv, "CNG Test", 640, 480);
  cng_put_pixel(Paris.getcoord('x'), Paris.getcoord('y'));
  cng_put_pixel(Marseille.getcoord('x'), Marseille.getcoord('y'));
  cng_current_color(0.6, 0.2, 0.7);
  cng_line(Paris.getcoord('x'), Paris.getcoord('y'), Marseille.getcoord('x'), Marseille.getcoord('y'));
  cng_main_loop();
  cng_destroy_window();

  return 0;
  }
