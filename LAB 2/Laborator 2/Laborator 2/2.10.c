#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int  matrice_patratica [MAX][MAX];

void citire_matrice(matrice_patratica a, int n)
{
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}


void afisare(matrice_patratica a, int n)
{
	int i, j;
	for (i = 0;i < n;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf("%d\t", a[i][j]);
		}
	}
}

void interschimbare(matrice_patratica a, int n)
{
	int i, j,aux;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i <j) {
				aux = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = aux;
			}


		}
	}
}


int main() {
	matrice_patratica a;
	int n;

	printf("n = ");
	scanf("%d", &n);
	printf("\n");

	citire_matrice(a, n);
	printf("\n");

	afisare(a, n);
	printf("\n");

	interschimbare(a, n);
	afisare(a, n);
	printf("\n");

	system("pause");
	return 0;
}
