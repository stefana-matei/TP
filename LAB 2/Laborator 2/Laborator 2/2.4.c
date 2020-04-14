#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void citire_matrice(int a[][25], int n)
{
	int i,j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void afisare_matrice(int a[][25], int n) 
{
	int i, j;
	for (i = 0;i < n;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf("%d\t", a[i][j]);
		}
	}
}

int suma_elementelor_pare(int a[][25], int n)
{
	int i, j, suma = 0;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			if (a[i][j] % 2 == 0) {
				if (i < j) {
					suma = suma + a[i][j];
				}
			}
		}
	}

	return suma;
}

int main() {
	int n,a[25][25];
	printf("n = ");
	scanf("%d", &n);

	printf("\n");

	citire_matrice(a, n);
	printf("\n");

	afisare_matrice(a, n);
	printf("\n");

	printf("Suma elementelor intregi pare aflate deasupra diagonalei principale este %d\n", suma_elementelor_pare(a, n));
	system("pause");
	return 0;

}