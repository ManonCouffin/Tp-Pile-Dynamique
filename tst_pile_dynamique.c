#include <stdio.h>
#include "pile_dynamique.h"
#include "element.h"



void main(void){
	PILE maPile;
	ELEMENT e;
	e = 1.6;
	
	maPile = init_PILE();
	
	printf("test affichage pile init \n");
	affiche_PILE(maPile);
	
	/*maPile = saisir_PILE();
	maPile = dePILE(maPile, &e);
	printf("La valeur en haut de la pile était de : %f \n", e);*/
	maPile = emPILE(maPile, e);
	printf("Ajout d'une nouvelle valeur :");
	scanf("%f", &e);
	maPile = emPILE(maPile, e);
	
	printf("test affichage nouvelle pile \n");
	affiche_PILE(maPile);
}
