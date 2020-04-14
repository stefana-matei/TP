#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void citire_matrice(float mat1[][30], int m, int n)
{
	int i, j;
	for (i = 1;i <= m;i++) {
		for (j = 1;j <= n;j++) {
			printf("mat1[%d][%d] = ", i, j);
			scanf("%f", &mat1[i][j]);
		}
	}
}

void afisare_matrice(float mat1[][30], int m, int n)
{
	int i, j;
	for (i = 1;i <= m;i++) {
		printf("\n");
		for (j = 1;j <= n;j++) {
			printf("%.1f\t",mat1[i][j]);
		}
	}
}

void transpusa(float mat1[][30], float mat2[][20], int m, int n)
{
	int i, j;
	for (i = 1;i <= m;i++) {
		for (j = 1;j <= n;j++) {
			mat2[j][i] = mat1[i][j];
		}
	}

	printf("Transpusa matricii este :\n");
	for (i = 1;i <= n;i++) {
		printf("\n");
		for (j = 1;j <= m;j++) {
			printf("%.1f\t", mat2[i][j]);
		}
	}

}

int main() {
	float mat1[20][30], mat2[30][20];
	int linie, coloana;

	printf("Numarul de linii : ");
	scanf("%d", &linie);
	printf("Numarul de coloane : ");
	scanf("%d", &coloana);

	printf("\n");
	citire_matrice(mat1, linie, coloana);

	printf("\n");
	afisare_matrice(mat1, linie, coloana);

	printf("\n");
	transpusa(mat1, mat2, linie, coloana);

	printf("\n");

	system("pause");
	return 0;
}