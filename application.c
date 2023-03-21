#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "pile_dynamique.h"

typedef struct VOIE_DE_WAGON{
	PILE Est;
	PILE Ouest;
	PILE Garage;
}VOIE_DE_WAGON;


int main(){
	//Définition d'un wagon et du nombre de wagons dans le train
	ELEMENT composant;
	int nbcomposants;
	ELEMENT wagon;
	VOIE_DE_WAGON voie;
	
	voie.Est =init_PILE();
	voie.Garage =init_PILE();
	voie.Ouest =init_PILE();
	
	//taille du train
	printf("Combien Voulez vous de composants dans votre train ? (en retirant la locomotive )\n");
	scanf("%d",&nbcomposants);
	printf("Saisissez les composants en partant du dernier\n");
	printf("ATTENTION ! Vous devez utiliser cette syntaxe : 1W, 2W, 1R, 4R, etc \n");
	for (int i=0; i<nbcomposants;i++){
		saisir_ELEMENT(&composant);
		voie.Est=emPILE(voie.Est,composant);
	}
	composant.numId=1;
	composant.categorie='L';
	voie.Est=emPILE(voie.Est,composant);
	printf("\n");
	

	printf("Position initial :\n");
	printf("Voie Est : ");
	affiche_PILE(voie.Est);
	printf("Voie Garage : ");
	affiche_PILE(voie.Garage);
	printf("Voie Ouest : ");
	affiche_PILE(voie.Ouest);
	printf("\n");
	
	//on dépile de la voie est pour empiler dans la voie garage 
	for (int i = 0; i < nbcomposants+1; i++){
		voie.Est=dePILE(voie.Est, &wagon);
		voie.Garage=emPILE(voie.Garage, wagon);
		

		printf("Passage du train de la voie Est à la voie Garage\n");
		printf("Voie Est : ");
		affiche_PILE(voie.Est);
		printf("Voie Garage : ");
		affiche_PILE(voie.Garage);
		printf("Voie Ouest : ");
		affiche_PILE(voie.Ouest);
		printf("\n");
	}
	
	//on dépile de la voie garage pour empiler dans la voie ouest
	for (int i=0;i<nbcomposants+1;i++){
		voie.Garage=dePILE(voie.Garage, &wagon);
		voie.Ouest=emPILE(voie.Ouest, wagon);
		
		printf("Passage du train de la voie Est à la voie Garage\n");
		printf("Voie Est : ");
		affiche_PILE(voie.Est);
		printf("Voie Garage : ");
		affiche_PILE(voie.Garage);
		printf("Voie Ouest : ");
		affiche_PILE(voie.Ouest);
		printf("\n");
	}
	
		//on affiche l'étape finale
		printf("Le train à fait demi-tour\n");

	
	return 0;
}
