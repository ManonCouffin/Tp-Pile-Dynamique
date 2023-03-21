#ifndef PILE_DYNAMIQUE_H 
#define PILE_DYNAMIQUE_H 


#include <stdio.h>
#include <stdlib.h>
#include "element.h"

//variables globales

typedef struct Cellule
{
	ELEMENT eCell;
	struct Cellule * ptr_CellSuiv;
	
}CELLULE;

typedef struct Pile
{
	CELLULE * ptr_Cell;
	
}PILE;

//fonctions

PILE init_PILE(void);

void affiche_PILE(PILE pile);

int PILE_estVide(PILE pile);

PILE emPILE(PILE pile, ELEMENT e);

PILE dePILE(PILE pile,ELEMENT* ancienE);

PILE saisir_PILE();

#endif
