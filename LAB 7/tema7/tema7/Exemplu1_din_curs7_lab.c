/*Se cere un număr n, iar apoi n numere întregi. Se cere să se sorteze crescător numerele.
Programul va utiliza doar strictul necesar de memorie. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>                     // pentru functiile malloc, free, exit

int main()
{
	int i, j, n;
	int *v;                                     // vector alocat dinamic, cu elemente de tip int
	int k,aux;

	printf(" n = ");
	scanf("%d", &n);

	// aloca dinamic un bloc de memorie pentru n elemente de tip int
	if ((v = (int*)malloc(n * sizeof(int))) == NULL) {
		// daca nu s-a reusit alocarea, afiseaza un mesaj
		// si iese din program returnand sistemului de operare un cod de eroare
		printf("memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}

	printf("\n");

	for (i = 0;i < n;i++) {
		printf("v[%d]=", i);
		scanf("%d", &v[i]);
	}

	do {                                         // bubble sort
		k = 0;                                   // daca au avut loc interschimbari
		for (i = 1;i < n;i++) {
			if (v[i - 1] > v[i]) {
				aux = v[i - 1];
				v[i - 1] = v[i];
				v[i] = aux;
				k = 1;
			}
		}
	} while (k);

	printf("\n");


	//afisare
	for (i = 0;i < n;i++)
		printf("%d\n", v[i]);

	free(v);                                   // elibereaza memoria alocata pentru v

	system("pause");
	return 0;
}
