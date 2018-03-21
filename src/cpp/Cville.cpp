#include <iostream>
#include <string>
#include "../inc/Cville.h"
#include <cstdlib>
#include <time.h>

using namespace std;
Cville::Cville(){
  ville=0;
  x=0;
  y=0;
}

void Cville::init(){
  static int i=0;
  srand(time(NULL) + i);
  ville=i++;
  x=rand()%1500;
  y=rand()%1500;
  cout<<"ville= "<<ville<<endl;
  cout<<"x= "<<x<<endl;
  cout<<"y= "<<y<<endl;

}


int Cville::getname(){
  return ville;
}

float Cville::getcoord(char c){
  if(c=='x')
    return x;
  if(c=='y')
    return y;
  else
    cerr<<"Error coordonnées! Veuillez rentrer x ou y !"<<endl;

}

Cville::~Cville(){
  cout<<"destructeur utilisé!"<<endl;
}
