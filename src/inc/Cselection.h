#ifndef _SEL
#define _SEL

#include"../inc/Cchemin.h"

typedef Cchemin* ptchemin;

class Cselection
  {
  private:
    Cchemin tab;
  public:
    Cselection();
    Cselection(ptchemin&, ptchemin&);
    ~Cselection();
    // ptchemin& operator=(const ptchemin&);
    ptchemin selec_naive(const ptchemin&, const ptchemin&, const ptchemin&);



  };


doublon(intez);


#endif
