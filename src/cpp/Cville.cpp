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
  x=rand()%1000;
  y=rand()%1000;
  // cout<<"ville= "<<ville<<endl;
  // cout<<"x= "<<x<<endl;
  // cout<<"y= "<<y<<endl;

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
  //cout<<"destructeur utilisé!"<<endl;
}

bool Cville::operator==(const Cville& v)
  {
  return (this == &v);
  }

ostream& operator<<(ostream& o, Cville& v)
  {
  o << v.getname()<< " :"<< endl;
  o << "    x = "<< v.x<< endl;
  o << "    y = "<< v.y<< endl;
  return o;
  }
