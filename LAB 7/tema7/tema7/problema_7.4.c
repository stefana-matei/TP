/*Aplicația 7.4:
Se citesc numere până la întâlnirea numărului 0.
Să se afișeze aceste numere în ordine inversă. 
Programul va folosi doar minimul necesar de memorie.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i, k, n = 0, aux_sortare = 0;
	int *a, *aux;


	a = malloc(sizeof(int));
	if (!a) {
		printf("Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}


	do {
		scanf("%d", &a[n]);
		aux = realloc(a, (n + 2) * sizeof(int)); 

		if (!aux) {
			printf("Nu pot redimensiona blocul.\n");
			free(a);
			exit(EXIT_FAILURE);
		}
		else {
			a = aux;
		}

		n++;

	} while (a[n-1] != 0);


	//sortare in ordine inversa
	do {
		k = 1;
		for (i = 0;i < n - 2;i++)
			if (a[i]< a[i + 1])
			{
				aux_sortare = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux_sortare;
				k = 0;
			}
	} while (!k);

	//afisarea numerelor
	printf("\nNumerele citite in ordine inversa sunt :\n");
	for (i = 0;i < n-1;i++) { //n-1 pentru a nu-l arata pe  0
		printf("%d ", a[i]);
	}

	printf("\n\n");

	free(a);
	system("pause");
	return 0;
}