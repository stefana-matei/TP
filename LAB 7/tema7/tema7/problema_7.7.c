/*Problema 7.7
Scrieţi un program care citeşte de la tastatură un număr N, apoi citeşte N numere întregi, iar la 
final afişează cele N numere în ordine inversă. Programul va folosi alocarea dinamică pentru memorarea celor 
N numere. 
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main() 
{
	int N, i, k, aux;
	int *tab;

	printf(" N = "); 
	scanf("%d", &N);

	if (!(tab = (int *)malloc(N * sizeof(int))))
	{
		printf("Eroare alocare dinamica!\n");
		exit(1);
	}


	printf("\nIntroduceti cele %d numere:\n", N);
	for (i = 0;i < N;i++)
		scanf("%d", &tab[i]);


	do {
		k = 1;
		for (i = 0;i < N - 1;i++)
		{
			if (tab[i] < tab[i + 1]) {
				aux = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aux;
				k = 0;
			}
		}
	} while (!k);

	printf("\nNumerele in ordine inversa : ");
	for (i = 0;i < N;i++)
		printf(" %d\t", tab[i]);
	printf("\n");


	free(tab);
	system("pause");
	return 0;
}
