#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wczytywanie.h"
#include "automat_komorkowy.h"
#include "wypisywanie.h"

char *usage=
	"\nAutomat Komórkowy \n"
	"Jako pierwszy argument należy podać nazwe pliku z początkową konfiguracją \n"
	"Drugi argument to liczba generacji do przeprowadznia\n\n";

void free_matrix(int **matrix, int rozmiar){

	int i;

	for(i=0 ; i < rozmiar ; i++)
		free(matrix[i]);

	free(matrix);
}

int main(int argc, char *argv[]) {

	int **plansza = NULL;
	int liczbaGen;
	int rozmiarPlanszy = 0;

	/* char nazwaPlikuWe[50]; */

	/* strcpy(nazwaPlikuWe, argv[1]); */

	if(argc < 2 ){

		printf("%s",usage);
	
	} else {

		liczbaGen = wczytajKonfiguracje(argv[1], &plansza, &rozmiarPlanszy,atof(argv[2]));
	
		zmienWiele(plansza, rozmiarPlanszy, liczbaGen);

		/* generujObraz(plansza, rozmiarPlanszy, 0); */

	}

	free_matrix(plansza,rozmiarPlanszy);

	return 0;
}
