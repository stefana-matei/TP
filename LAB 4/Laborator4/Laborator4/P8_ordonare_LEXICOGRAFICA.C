/*P8. Se citesc datele despre elevii unei clase, respectiv numele şi data naşterii. 
Să se ordoneze elevii în ordinea LEXICOGRAFICA după nume şi să se afişeze această situaţie.*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
	char nume[50];
	int	data;
}clasa;

void citire(clasa *c, int i)
{
	printf("Nume : ");
	scanf("%s", (c + i)->nume);
	printf("Data : ");
	scanf("%d", &(c + i)->data);
}

void afisare_factor(clasa *c, int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("%s %d\n", (c + i)->nume, (c + i)->data);
}

void sortare(clasa *c, int *n)
{
	clasa aux;
	int i, k;
	do {
		k = 1;
		for (i = 1; i <= *n; i++)
		{
			if (strcmp((c + i - 1)->nume, (c + i)->nume) > 0)
			{
				aux = *(c + i);
				*(c + i) = *(c + i - 1);
				*(c + i - 1) = aux;
				k = 0;
			}
		}
	} while (!k);
}

int main()
{
	clasa c[30];
	int n, i;
	printf("Numarul de elevi ai clasei: ");
	scanf("%d", &n);
	printf("\n");

	for (i = 0;i < n;i++)
		citire(c, i);
	printf("\n");

	sortare(c, &n);
	printf("\n");

	afisare_factor(c, n);
	printf("\n");
	system("pause");
	return 0;
}