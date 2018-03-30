#include <cstdlib>
#include <ctime>
#include "Cmutation.h"

//constructeur par défaut
Cmutation::Cmutation(){
	new_valeur=0;
	choix_chemin=0;
	choix_empl=0;
}


//Constructeur par paramètres
Cmutation::Cmutation(int new_v,int choix_emp,int choix_chm){

	//nouvelle valeur
	int new_valeur=new_v;
	//emplacement
  int choix_empl=choix_emp;
	//chemin
	int choix_chemin=choix_chm;

}


int Cmutation::chemin_aleatoire(Cpopulation &pop){
	srand(time(NULL));
	//taille de la population
	int taille_pop=pop.gettaille();
	//choisir le chemin
	int choix_chemin=rand()%taille_pop;

	return pop[choix_chemin];
}

int Cmutation::valeur_aleatoire(){
	srand(time(NULL));
	int new_valeur=rand()%150;
	return new_valeur;
}

int Cmutation::emplacement_aleatoire(Cchemin &chm){
	srand(time(NULL));
	//taille du chemin
	int taille_chemin=chm.getNb();
	//choisir l'emplacement
	int choix_empl=rand()%taille_chemin;
	return choix_empl;
}

void Cmutation::Affiche(){
	cout<<"nouvelle valeur= "<<new_valeur<<endl;
	cout<<"choix du chemin= "<<choix_chemin<<endl;
	cout<<"choix de l'emplacement= "<<choix_empl<<endl;

}
