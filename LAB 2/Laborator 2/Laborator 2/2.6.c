#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void adaugare_linie_nul(int a[][25], int m, int n)
{
	int i, j, linie = 2;
	for (i = m + 1; i > 0; i--) {
		for (j = 0; j < n; j++) {
			if (i > linie) {
				a[i + 1][j] = a[i][j];
			}
			if (i == linie + 1) {
				a[i][j] = 0;
			}
		}
	}
}


void matrice_finala(int a[][25], int m, int n) {
	int i, j;
	for (i = 0; i < m + 1; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}


int main() {
	int i, j, a[26][25], linie, coloana;

	printf("Numarul de linii : ");
	scanf("%d", &linie);
	printf("Numarul de coloane : ");
	scanf("%d", &coloana);

	printf("\n Matricea initiala: \n");


	for (i = 0; i < linie; i++) {
		for (j = 0; j < coloana; j++) {
			a[i][j] =	1;
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}

	
	printf("\n");
	adaugare_linie_nul(a, linie, coloana);

	printf("\nMatricea rezultata: \n");
	matrice_finala(a, linie, coloana);

	system("pause");
	return 0;
}