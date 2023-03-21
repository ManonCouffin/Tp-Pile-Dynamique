#include <stdio.h>
#include <stdlib.h>
#include "pile_dynamique.h"
#include "element.h"

//fonctions

PILE init_PILE(void)
{
	PILE maPile;
	maPile.ptr_Cell= NULL; //la pile pointe vers rien
	return maPile;
}

void affiche_PILE(PILE pile)
{
	if(	pile.ptr_Cell == NULL){
		printf("La pile est Vide \n");
	}
	else {
		do
		{
			affiche_ELEMENT(pile.ptr_Cell->eCell);
			pile.ptr_Cell = pile.ptr_Cell->ptr_CellSuiv;
			
		} while(pile.ptr_Cell != NULL);
	}

}


int PILE_estVide(PILE pile)
{
	if(pile.ptr_Cell == NULL)
	{
		//printf("La pile est vide \n");	
		return 1;
	}
	else
		//printf("La pile n'est pas vide \n");	
		return 0;
}

PILE emPILE(PILE pile, ELEMENT e)
{
	CELLULE * cell = (CELLULE *) malloc(sizeof (CELLULE));
	cell->eCell = e;
	cell->ptr_CellSuiv = pile.ptr_Cell;
	pile.ptr_Cell = cell;	
	return pile;
}

PILE dePILE(PILE pile, ELEMENT * ancienE)
{
	if(PILE_estVide(pile)){
		printf("La pile est vide \n");
	}
	else {
		*ancienE = affect_ELEMENT(*ancienE,pile.ptr_Cell.eCell);
		pile = pile->ptr_CellSuiv;
	}
	return pile;

}

PILE saisir_PILE(){
	int i, valeur;
	ELEMENT e;
	PILE maPile;
	
	maPile = init_PILE();
	affiche_PILE(maPile);
	
	printf("Nombre de valeur pour la pile : ");
	scanf("%d",&valeur);	

	for(i=0; i<valeur; i++){
		printf("Valeur n°%d : ",(i+1));
		e = saisir_ELEMENT();
		pile = emPILE(pile, e);
	}
	return maPile;
}
