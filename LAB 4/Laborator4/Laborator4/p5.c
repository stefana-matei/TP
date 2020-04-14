/*Sa se citeasca de la tastatura 2 texte, retinute in  sirurile t1 si  t2. 
Sa se determine vocala(vocalele) care apare(apar) de cele mai multe ori in cele 2 texte.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>


void aparitie_vocale(char sir1[], char sir2[])
{
	int numar_vocale[10], m, n, i, j, max = 0;
	char vocale[] = "AaEeIiOoUu";

	m = strlen(sir1);
	n = strlen(sir2);

	for (i = 0;i < 10;i++)
		numar_vocale[i] = 0;

	for (i = 0;i < m;i++)   //sir1
		for (j = 0;j < 10;j++)
			if (sir1[i] == vocale[j])
				numar_vocale[j]++;


	for (i = 0;i < n;i++) //sir2
		for (j = 0;j < 10;j++)
			if (sir2[i] == vocale[j])
				numar_vocale[j]++;

	for (i = 0;i < 10;i++)
		if (numar_vocale[i] > max)
			max = numar_vocale[i];

	for (i = 0;i < 10;i++)
		if (max == numar_vocale[i])
			printf("Vocala %c exista in siruri de %d ori\n", vocale[i], numar_vocale[i]);
}

int main()
{
	char t1[20], t2[20];
	printf("Introduceti sirul 1 \n");
	gets(t1);
	printf("\n");

	printf("Introduceti sirul 2 \n");
	gets(t2);
	printf("\n");

	aparitie_vocale(t1, t2);
	system("pause");
	return 0;
}