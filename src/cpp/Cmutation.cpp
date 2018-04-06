#include <cstdlib>
#include <ctime>
#include "Cmutation.h"

//constructeur par défaut
Cmutation::Cmutation(){
	new_valeur=0;
	choix_chemin=0;
	choix_empl=0;
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

int Cmutation::valeur_aleatoire(){
	srand(time(NULL));
	new_valeur=rand()%150;
	cout<<"val= "<<new_valeur<<endl;
	return new_valeur;
}

Cville Cmutation::emplacement_aleatoire(Cchemin &chm){
	srand(time(NULL));
	//taille du chemin
	int taille_chemin=chm.getNb();
	//choisir l'emplacement
	choix_empl=rand()%taille_chemin;
	return chm[choix_empl];
}

void Cmutation::Affiche(){
	cout<<"nouvelle valeur= "<<new_valeur<<endl;
	cout<<"choix du chemin= "<<choix_chemin<<endl;
	cout<<"choix de l'emplacement= "<<choix_empl<<endl;

}
