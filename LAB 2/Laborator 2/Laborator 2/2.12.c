#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

void initializare_persoane(int* pers[MAX], int n)
{
	int i, j;
	for (i = 0;i < n;i++) {
		pers[i] = 0;
	}
}

void prieteni_citire(int* pers[MAX], int n)
{
	int i;
	for (i = 0;i < n;i++) {
		printf("[%d] : ", i);
		scanf("%d", &pers[i]);
	}
}

void afisare(int* pers[MAX], int n, int afisare_prieteni)
{
	int i;
	for (i = 0;i < n;i++) {

		if (afisare_prieteni) 
			printf("persoana %d are %d prieteni \n", i, pers[i]);
		else 
			printf("persoana [%d] \n", i);
		
	}
}




int main() {
	int pers[MAX];
	int n;

	printf("n = ");
	scanf("%d", &n);
	printf("\n");

	initializare_persoane(&pers, n);
	printf("\n");

	afisare(&pers, n, 0);
	printf("\n\n");

	prieteni_citire(&pers, n);
	printf("\n\n");

	afisare(&pers, n, 1);
	printf("\n\n");


	system("pause");
	return 0;
}

