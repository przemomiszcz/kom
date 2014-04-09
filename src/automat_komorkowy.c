#include <stdio.h>
#include <stdlib.h>
#include "automat_komorkowy.h"
#include "wypisywanie.h"


void zmienGeneracje(int **plansza, int rozmiarPlanszy, int nrGen) {

        int **poprzedniaGen;
        int i = 0;
        int j = 0;

        poprzedniaGen = (int**)malloc(sizeof(int*)*(rozmiarPlanszy + 2));    /* alokujemy pamiec dla poprzedniej planszy */

        for (i = 0; i<rozmiarPlanszy + 2; i++)
        	poprzedniaGen[i] = (int*)malloc(sizeof(int)*(rozmiarPlanszy + 2));

        for (i = 0; i<rozmiarPlanszy + 2; i++) {
                for (j = 0; j<rozmiarPlanszy + 2; j++)
                        poprzedniaGen[i][j] = plansza[i][j];
        }

        for (i = 1; i<rozmiarPlanszy; i++) {
                for (j = 1; j<rozmiarPlanszy; j++) {

                        int ileZywych = 0;
                        int akcja = 0;

                        ileZywych = sprawdzSasiadow(i, j, poprzedniaGen);

                        akcja = zasady(ileZywych, poprzedniaGen[i][j]);

                        plansza[i][j] = zmienStan(akcja, poprzedniaGen[i][j]);
                }
        }

        zapiszKonfiguracje(plansza, nrGen, rozmiarPlanszy);

        wypisywanie(plansza, rozmiarPlanszy);

        generujObraz(plansza, rozmiarPlanszy, nrGen);

        /*printf("nowa\n");

        wypisywanie(poprzedniaGen, rozmiarPlanszy);*/

}


void zmienWiele(int **plansza, int rozmiarPlanszy, int liczbaGen) {

        int i = 1;

        for (i = 1; i <= liczbaGen; i++)
                zmienGeneracje(plansza, rozmiarPlanszy, i);
}

int sprawdzSasiadow(int x, int y, int **plansza) {

        int i;
        int j;
        int licznik = 0;

        for (i = x - 1; i < x + 2; i++) {
        	for (j = y - 1; j < y + 2; j++) {
                        if (i != x || j != y) {/* eliminujemy rozpatrywana komorke */
                                if (plansza[i][j] == 1)
                                        licznik++;
                        }
                }
        }

        return licznik;
}

int zasady(int ileZywych, int stanKomorki) {

        if (stanKomorki == 0 ) {
                if (ileZywych != 3)
                        return 0;
                else
                	return 1;
        } else {
                if (ileZywych == 2 || ileZywych == 3)
                        return 1;
                else
                        return -1;
        }
}


int zmienStan(int akcja, int stanKomorki) {

        if (akcja == -1) {
                return 0;
        }

	else if (akcja == 0) {

                return stanKomorki;

        }

        else {

                return 1;

        }

}
