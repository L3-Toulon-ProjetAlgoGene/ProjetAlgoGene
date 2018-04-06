#include <cstdlib>
#include <ctime>
#include "Cmutation.h"

//constructeur par défaut
Cmutation::Cmutation(){
	new_valeur=0;
	choix_chemin=0;
	choix_empl1=0;
	choix_empl2=0;
}




Cchemin Cmutation::chemin_aleatoire(Cpopulation &pop){
	srand(time(NULL));
	//taille de la population
	int taille_pop=pop.gettaille();
	cout<<"taille= "<<taille_pop<<endl;
	//choisir le chemin
	choix_chemin=rand()%taille_pop;
	cout<<"choix_chemin= "<<choix_chemin<<endl;

	return pop[choix_chemin];
}

/*int Cmutation::valeur_aleatoire(){
	srand(time(NULL));
	new_valeur=rand()%150;
	cout<<"val= "<<new_valeur<<endl;
	return new_valeur;
}*/

void Cmutation::emplacement_aleatoire(Cchemin &chm){
	srand(time(NULL));
	//taille du chemin
	int taille_chemin=chm.getNb();
	//choisir l'emplacement
	choix_empl1=rand()%taille_chemin;
	srand(time(NULL));
	choix_empl2=rand()%taille_chemin;
	while(choix_empl2==choix_empl1){
		choix_empl2=rand()%taille_chemin;
	}
	//return chm[choix_empl1];
}

void Cmutation::echange(Cchemin& chm){
	Cville t=chm[choix_empl1];
	//cout<<"t="<<t.getname()<<endl;
	chm.putVal(chm[choix_empl2],choix_empl1);
	//this->Affiche_chemin(chm);
	chm.putVal(t,choix_empl2);

}

void Cmutation::Affiche_chemin(Cchemin &chm){
	for(int i=0;i<chm.getNb();i++){
		cout<<chm[i].getname()<<",";
	}
	cout<<endl;
}


void Cmutation::Affiche(){
	//cout<<"nouvelle valeur= "<<new_valeur<<endl;
	//cout<<"choix du chemin= "<<choix_chemin<<endl;
	cout<<"choix de l'emplacement 1= "<<choix_empl1<<endl;
	cout<<"choix de l'emplacement 2= "<<choix_empl2<<endl;

}

/*
#include <iostream>
#include "Cmutation.h"
#include "Cpopulation.h"
#include "Cchemin.h"
#include "Cville.h"
using namespace std;

int main(){
	Cville a,b,c,d,e,f,g,h,i;
	a.init();
	b.init();
	c.init();
	d.init();
	e.init();
	f.init();
	g.init();
	h.init();
	i.init();
	Cville tab_ville[3]={a,b,c};
	Cville tab_ville2[3]={d,e,f};
	Cville tab_ville3[3]={g,h,i};
	Cchemin chm1(tab_ville,3);
	Cchemin chm2(tab_ville2,3);
	Cchemin chm3(tab_ville3,3);
	Cchemin tab_chemin[3]={chm1,chm2,chm3};
	Cpopulation popul(tab_chemin,3);
	Cmutation x;
	//x.Affiche();
	Cchemin ch=x.chemin_aleatoire(popul);
	x.Affiche_chemin(ch);
	//x.valeur_aleatoire();
	x.emplacement_aleatoire(ch);
  x.Affiche();
	x.echange(ch);
	x.Affiche_chemin(ch);
	cout<<"1"<<endl;
	return 0;
}
*/
