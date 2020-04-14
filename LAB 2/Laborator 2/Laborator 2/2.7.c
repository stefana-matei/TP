#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int matrice[10][10];

void citire_matrice_a(matrice a, int m, int n)
{
	int i, j;
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void citire_matrice_b(matrice b, int n, int p)
{
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < p;j++) {
			printf("b[%d][%d] = ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
}

void afisare_matrice_a(matrice a, int m, int n,char *s)
{
	int i, j;
	printf("Matricea %s : \n",s);
	for (i = 0;i < m;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf(" \t%d ",a[i][j]);
		}
	}

}


void afisare_matrice_b(matrice b, int n, int p,char*s)
{
	int i, j;
	printf("Matricea %s : \n", s);
	for (i = 0;i < n;i++) {
		printf("\n");
		for (j = 0;j < p;j++) {
			printf(" \t%d ", b[i][j]);
		}
	}

}

void inmultire_matrici(matrice a, matrice b, matrice c, int m, int n, int p)
{
	int i, j,k;
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			c[i][j] = 0;
			for (k = 0;k < p;k++)
				c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
		}
	}
}

void afisare_matrice_c(matrice c,int n,int p, char* s)
{
	int i, j;
	printf("\nMatricea %s(c) este:\n", s);
	for ( i = 0;i < n;i++) {
		printf("\n");
		for (j = 0;j < p;j++) {
			printf("\t%d", c[i][j]);
		}
	}
}


int main() {
	int m, n, p;
	matrice a, b, c;
	printf("Introduceti dimensiunile matricelor a si b : \n");
	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	printf("p = ");
	scanf("%d", &p);
	printf("\n");

	citire_matrice_a(a, m, n);
	printf("\n");

	citire_matrice_b(b, n, p);
	printf("\n");

	afisare_matrice_a(a, m, n,"a");
	printf("\n");

	afisare_matrice_b(b, n, p,"b");
	printf("\n\n");

	inmultire_matrici(a, b, c, m, n, p);
	afisare_matrice_c(c,n ,p, "a*b");
	printf("\n\n");

	system("pause");
	return 0;
	
}