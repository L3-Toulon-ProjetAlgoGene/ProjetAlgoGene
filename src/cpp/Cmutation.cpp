#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mutation.h"
using namespace std;

void simulpop(int *tab){
	
	tab=new int[5];
	int i;
	for(i=0;i<8;i++){
		tab[i]=i;
		cout<<tab[i]<<endl;
		}
}


void aleatoire(int * tab, int nb_v){
        
        for(int i=0;i<nb_v;i++){
		int new_v=rand()%150;
		cout<<"new_v="<<new_v<<endl;
        	int emp=rand()%6;
		cout<<"emp="<<emp<<endl;
		tab[emp]=new_v;
	}
}

void Affiche_tab(int *tab){
	for(int i=0;i<8;i++){
		cout<<tab[i]<<endl;
	}
}
	





