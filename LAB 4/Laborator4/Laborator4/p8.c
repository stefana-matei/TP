/*Sa se citeasca de la tastatura un text incheiat cu caracterul “.”. 
Scrieti un program care plaseaza caracterele din textul citit intr-o matrice patratica, caracter cu caracter, in ordine pe linii de sus in jos si pe fiecare linie de la stanga la dreapta.
Daca nu sunt suficiente caractere se completeaza matricea cu spatii. Afisati matricea obtinuta.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>

void matrice(char s[])
{
	int mat[20][20], i, j, k = strlen(s), nr = 0;
	float n;

	n = sqrt(k);

	for (i = 0;i < n;i++)
		for (j = 0;j < n;j++){
			if (s[nr] != NULL && nr < k - 1)
			{
				mat[i][j] = s[nr];
				nr++;
			}
			else 
				mat[i][j] = ' ';
		}

	for (i = 0;i < n;i++){ //afisare
		printf("\n");
		for (j = 0;j < n;j++)
			printf("%c\t", mat[i][j]);
	
	}
}

int main()
{
	char s[100];
	printf("Introduceti sirul \n");
	fflush(stdin);
	gets(s);
	printf("\n");

	printf("Matricea este: \n");
	matrice(s);
	printf("\n");
	system("pause");
	return 0;
}