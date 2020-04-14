/*Problema 7.8
Aceeaşi problemă ca mai sus, cu diferenţa că nu se ştie de la început câte numere vor fi introduse.
 Programul va începe direct cu citirea numerelor, fără a-l citi pe N. Citirea se va încheia în momentul în
 care se introduce numărul 0. Programul va folosi alocarea dinamică astfel încât spaţiul de memorie consumat 
să fie minim
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int main() 
{
	int k, i, aux, count = 0, aw = 1;
	int *tab;
	

	if (!(tab = (int *)malloc(20 * sizeof(int)))){
		printf("Eroare alocare!\n");
		exit(1);
	}


	while (tab[count - 1] != 0) {
		if (!(tab = (int*)realloc(tab, (aw + 1) * sizeof(int)))){
			printf("Eroare realocare!\n");
			exit(1);
		}
		scanf("%d", &tab[count]);
		count++;
		aw = count;
	}


	do {
		k = 1;
		for (i = 0;i < count;i++)
		{
			if (tab[i] < tab[i + 1]) {
				aux = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aux;
				k = 0;
			}
		}
	} while (!k);


	for (i = 0;i < count;i++)
		printf("%d\t", tab[i]);

	printf("\n");
	free(tab);
	system("pause");
	return 0;
}