#include <stdio.h>
#include <stdlib.h>
#include "wczytywanie.h"
#include <string.h>
#include "wypisywanie.h"

int atoib(char liczbaGen[]) {

        char c;
        int i = 0;

        while ((c = liczbaGen[i++]) != '\0') {
                if (c <= '0' || c >= '9')
                        return -1;
        }

        return atoi(liczbaGen);
}

int wczytajKonfiguracje(int argc, char *argv[], int*** plansza, int *rozmiarPlanszy) {
       
	 /* wczytywanie ilosci generacji z klawy! */
        
	char nazwaPlikuWe[50];
        int liczbaGen = 5;
        int i=0;
        int j=0;
	FILE * plikWe;

        strcpy(nazwaPlikuWe, "altstart");

        printf("Podaj liczbe generacji\n");

        if (argc == 3) {
                strcpy(nazwaPlikuWe, argv[1]);
                liczbaGen = atoib(argv[2]);
                if (liczbaGen == -1) {
                        liczbaGen = 10;
                        printf("Nie mozna odczytac liczby generacji\n");
                }
        } else {
                printf("wczytuje domyslna konfiguracje\n");
        }

        strcat(nazwaPlikuWe, ".txt");

        printf("%s %d\n", nazwaPlikuWe, liczbaGen);

        plikWe = fopen(nazwaPlikuWe, "r");

        if (plikWe == NULL)
                perror("nie udalo sie otworzyc pliku");

        fscanf(plikWe, "%d", rozmiarPlanszy); /* wczytujemy rozmiar planszy z pliku */

	*plansza = (int**)malloc(sizeof(int*)*(*rozmiarPlanszy + 2));    /* alokujemy pamiec dla planszy */

        for (i = 0; i<*rozmiarPlanszy + 2; i++)
                (*plansza)[i] = (int*)malloc(sizeof(int)*(*rozmiarPlanszy + 2));

        for (i = 0; i<*rozmiarPlanszy + 2; i++) {  /* for - tworzymy obramowanie zerowe dla planszy */
                (*plansza)[i][0] = 0;
                (*plansza)[i][*rozmiarPlanszy + 1] = 0;
                if (i == 0 || i == *rozmiarPlanszy + 1) {
                        for (j = 1; j<*rozmiarPlanszy + 1; j++)
                                (*plansza)[i][j] = 0;
                }
        }

        for (i = 1; i <= *rozmiarPlanszy; i++) {
                for (j = 1; j <= *rozmiarPlanszy; j++)
                        fscanf(plikWe, "%d", &(*plansza)[i][j]);
        }

        /*      for(i=0; i<rozmiarPlanszy+2; i++) {

        for(j=0; j< rozmiarPlanszy+2; j++) {

        printf("%d ", plansza[i][j]); // do innego modulu

        }

        putchar('\n');

        } */

        fclose(plikWe);

	wypisywanie(*plansza, *rozmiarPlanszy);

        zapiszKonfiguracje(*plansza, 123, *rozmiarPlanszy);

        return liczbaGen;

}

