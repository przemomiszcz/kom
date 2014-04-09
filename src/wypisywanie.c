#include <stdio.h>
#include "wypisywanie.h"
#include <stdlib.h>
#include <string.h>


void zapiszKonfiguracje(int **plansza, int nrGen, int rozmiarPlanszy) {

        FILE* plikWy;
        int i = 0;
        int j = 0;
        char nazwaPlikuWy[1000];

        /*sprintf(nazwaPlikuWy, "koniec.txt"); */

        liczbaNaTekst(nrGen, nazwaPlikuWy);

        strcat(nazwaPlikuWy, ".txt");

        plikWy = fopen(nazwaPlikuWy, "w");

        fprintf(plikWy, "%d", rozmiarPlanszy);

        for (i = 1; i <= rozmiarPlanszy; i++){

                fprintf(plikWy, "%c", '\n');

                for (j = 1; j <= rozmiarPlanszy; j++)
                        fprintf(plikWy, "%d ", plansza[i][j]);
        }

        fclose(plikWy);
}

void liczbaNaTekst(int liczba, char* tekst) {

        int licznik = 0;
	int dlugosc;
        int i = 0;
        char temp[1000];

        if (liczba == 0) {
                temp[0] = '0';
                /* licznik++; */
        }

        while (liczba != 0) {
                temp[licznik++] = (liczba % 10) + '0';
                liczba = liczba/10;
        }

	dlugosc = licznik;

        for (i = 0; i < dlugosc; i++)
                tekst[i] = temp[--licznik];

        tekst[i] = '\0';
}

void wypisywanie(int **plansza, int rozmiarPlanszy) {

        int i = 0;
        int j = 0;

        for (i = 0; i<rozmiarPlanszy + 2; i++) {
                for (j = 0; j< rozmiarPlanszy + 2; j++)
                        printf("%d ", plansza[i][j]); /* do innego modulu */
                
		putchar('\n');
        }

        putchar('\n');
}

void generujObraz(int **plansza, int rozmiarPlanszy, int nrGen) {

        const int skala = 10;
        const int dimx = rozmiarPlanszy *skala;
        const int dimy = rozmiarPlanszy * skala;
        int i = 0;
        int j = 0;
        char nazwaPlikuWy[1000];
	FILE * fp;

        /*strcpy(nazwaPlikuWy, "koniec.txt"); */

        liczbaNaTekst(nrGen, nazwaPlikuWy);

        strcat(nazwaPlikuWy, ".pbm");

        fp = fopen(nazwaPlikuWy, "w");

        fprintf(fp, "P1\n%d %d\n", dimx, dimy);

	/*for (i = 0; i < rozmiarPlanszy; i++) {

                for (j = 0; j < rozmiarPlanszy; j++) {

                        for (k = skala*i; k < skala; k++) {

                                for (l = skala*j; l < skala; l++) {

                                        fprintf(fp, "%c ", plansza[i][j]);

                                }

                        }

                }

        }

*/

        for (i = 0; i < dimx; i++) { /* wiersze w pliku tekstowym */
                for (j = 0; j < dimy; j++)
                        fprintf(fp, "%d ", plansza[(i/skala)+1][(j/skala)+1]);
        }

        fclose(fp);
}
