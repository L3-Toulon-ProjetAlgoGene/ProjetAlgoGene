#ifndef _SEL
#define _SEL

#include"../inc/Cchemin.h"

typedef Cchemin* ptchemin;

class Cselection
  {
  private:
    Cchemin tab;
  public:
    selection();
    selection(ptchemin&, ptchemin&);
    ~selection();
    ptchemin& operator=(const ptchemin&);



  };





#endif
