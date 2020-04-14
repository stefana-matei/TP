/*
O matrice rară (contine 90% din elemente 0) este păstrată economic sub forma unei structuri, care conţine următoarele câmpuri:
int l,c - numărul de linii/coloane al matricei rare; 
int n - numărul de elemente nenule
int linii[] - vectorul ce păstrează liniile în care se află elemente nenule
int coloane[] - vectorul ce păstrează coloanele în care se află elemente nenule
float nenul[] - vectorul ce păstrează elementele nenule

Să se definească funcţii pentru:
•	citirea unei matrice rare;
•	afişarea unei matrice rare (ca o matrice, cu tot cu zerouri)
•	adunarea a două matrice rare.
Observatii :
Vectorii linii[], coloane[], nenule[] vor avea fiecare cate n elemente.
Elementul nenul cu valoare nenule[index] se afla pe linia linii[index] si coloana coloane[index].
Elementele vor fi citite in ordinea crescatoare a liniilor, iar elementele de pe aceeasi linie in ordinea crescatoare a coloanelor.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>


void cirire(int a[][10], int numar_linii, int numar_coloane)
{
	int i, j, numar_nenule, numere_nenule[100], linii[10], coloane[10];

	printf("Introduceti numarul de linii :  ");
	scanf("%d", &numar_linii);
	printf("\n");

	printf("Introduceti numarul de coloane :  ");
	scanf("%d", &numar_coloane);
	printf("\n");

	printf("Introduceti numarul de elemente nenule : ");
	scanf("%d", &numar_nenule);
	printf("\n");

	printf("Introduceti elementele nenule :  ");
	for (i = 1;i <= numar_nenule;i++)
		scanf("%d", &numere_nenule[i]);
	printf("\n");

	printf("Introduceti liniile cu elemente nenule :  ");
	for (i = 1;i <= numar_nenule;i++)
		scanf("%d", &linii[i]);
	printf("\n");

	printf("Introduceti coloanele cu elemente nenule :  ");
	for (i = 1;i <= numar_nenule;i++)
		scanf("%d", &coloane[i]);
	printf("\n");

	for (i = 1;i <= numar_linii;i++)
		for (j = 1;j <= numar_coloane;j++)
			a[i][j] = 0; //restul elementelor ce vor fi nule


	for (i = 1;i <= numar_nenule;i++)
		a[linii [i] ][coloane [i] ] = numere_nenule[i];


	for (i = 1;i <= numar_linii;i++){
		for (j = 1;j <= numar_coloane;j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void adunare(int a[][20], int b[][20], int s[][20], int *n, int *m)
{
	int i, j;
	for (i = 0;i < *n;i++)
		for (j = 0;j < *m;j++)
			s[i][j] = a[i][j] + b[i][j];
}

int main()
{
	int a[10][10], b[10][10], s[10][10], n = -1, m = -1;
	cirire(&a, n, m);

	system("pause");
	return 0;
}