#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10


void afisare_orase(int oras[MAX], int n)
{
	int i;
	for (i = 0;i < n;i++) {
		printf("Orasul[%d] \t", i);

	}
}


void citire_afisare_distanta(int *distanta[MAX][MAX], int n,char * unitate)
{
	int i,j;
	for (i = 0;i < n;i++) {
		for (j = i + 1;j < n;j++) {
			printf("Distanta dintre Orasul(%d) si Orasul(%d) : ", i, j);
			scanf("%d", &distanta[i][j]);
		}
	}

	printf("\n");

	for (i = 0;i < n;i++) {
		for (j = i + 1;j < n;j++) {
			if (distanta[i][j] != 0) {
				printf("Distanta dintre (%d,%d) este de %d %s. \n", i, j, distanta[i][j],unitate);
			}
			else
				printf("Nu exista drum direct intre aceste orase!\n");
		}
	}
}


int main() {
	int oras[MAX];
	int *distanta[MAX][MAX];
	int n;

	printf("Scrieti numarul de orase dorit = ");
	scanf("%d", &n);
	printf("\n");

	afisare_orase(oras, n);
	printf("\n\n");

	citire_afisare_distanta(&distanta, n," km");
	printf("\n\n");


	system("pause");
	return 0;
}