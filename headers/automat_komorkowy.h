#ifndef _AUTOMAT_KOMORKOWY_H
#define _AUTOMAT_KOMORKOWY_H

void zmienGeneracje(int **plansza, int rozmiarPlanszy, int i);

void zmienWiele(int **plansza, int rozmiarPlanszy, int liczbaGen);

int sprawdzSasiadow(int x, int y, int **plansza);

int zasady(int ileZywych, int stanKomorki);

int zmienStan(int akcja, int stanKomorki);

#endif
