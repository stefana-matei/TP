#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void citire_matrice(int v[][10], int n)
{
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			printf("v[%d][%d] = ", i, j);
			scanf("%d", &v[i][j]);
		}
	}
}

void afisare_matrice(int v[][10], int n)
{
	int i, j;
	for (i = 0;i < n;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf(" %d\t ", v[i][j]);
		}
	}

}

void verificare_matrice_unitate(int v[][10], int n)
{
	int i, j, verificareprincipala = 1, verificaresecundara = 1;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {

			if (i == j) {
				if (v[i][j] != 1) {
					verificareprincipala = 0;
				}
			}

			if (j == n-i+1) {
				if (v[i][n - i + 1] != 0) {
					verificaresecundara = 0;

				}
			}
				
		}
	}

	if (verificareprincipala && verificaresecundara ) 
		printf("Matricea este unitate!\n\n");
	else
		printf("Nu este matrice unitate!\n");
	
	
}


int main() {
	int n, a[10][10];
	printf("n = ");
	scanf("%d", &n);
	citire_matrice(a, n);
	printf("\n\n");
	afisare_matrice(a, n);
	printf("\n");
	verificare_matrice_unitate(a, n);
	system("pause");
	return 0;




}