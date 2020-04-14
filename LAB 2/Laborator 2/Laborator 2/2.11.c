#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#define MAX 20

void citire_afisare(int** a, int n)
{
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	printf("\n");

	for (i = 0;i < n;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf("%3d\t", a[i][j]);
		}
	}
}

void suma_linie(int** a, int n,int *x[MAX])
{
	int sumalinie, i, j;
	for (i = 0;i < n;i++) {
		sumalinie = 0;
		for (j = 0;j < n;j++) {
			sumalinie += a[i][j];
			x = sumalinie;//vectorul x ce va contine suma liniilor
		}
		printf("Suma de pe linia %d este %d\n", i + 1,x );
	}

	
}

void suma_coloana(int** a, int n,int *y[MAX])
{
	int sumacoloana, i, j;
	for (i = 0;i < n;i++) {
		sumacoloana = 0;
		for (j = 0;j < n;j++) 
		{
			sumacoloana += a[j][i];
			y = sumacoloana;
		}
		printf("Suma de pe coloana %d este %d\n", i + 1, y);
	}
}

int main() {
	int** a;
	int x[MAX],y[MAX];
	int n, i;

	printf("Dati numarul de linii si coloane = ");
	scanf("%d", &n);
	printf("\n");

	//memorie pt vectorul de pointeri la linii
    //malloc aloca in zona heap n octeti si intoarce un pointer la  inceputul acestei zone sau NULL daca alocarea nu e posibila

	a = malloc((n) * sizeof(int*));
	for (i = 0; i < n; i++)
	{   //memorie pt fiecare linie
		a[i] = malloc((n) * sizeof(int));
	}

	citire_afisare(a, n);
	printf("\n\n");
	suma_linie(a, n, &x);
	printf("\n");
	suma_coloana(a, n,&y);
	printf("\n");
	system("pause");
	return 0;
}