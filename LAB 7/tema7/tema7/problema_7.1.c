/*Să se scrie o funcție citire(n), care primește ca argument un număr n și alocă dinamic un vector de n numere întregi, pe care 
îl inițializează cu valori citite de la tastatură și îl returnează.
În programul principal se citesc două numere, m și n, iar apoi, folosind funcția citire,
se citesc elementele a doi vectori, primul de m elemente iar al doilea de n elemente.
Să se afișeze toate elementele din primul vector care se regăsesc și în al doilea vector.
Programul va utiliza doar strictul necesar de memorie.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int citire(int n)
{
	int i, j;
	int *v;

	v = (int*)malloc(n * sizeof(int));
	if ((v = (int*)malloc(n * sizeof(int))) == NULL) {
		printf("Memorie insuficienta!\n");
		exit(EXIT_FAILURE);
	}


	//citire
	for (i = 0; i < n; i++) {
		printf("v[%d] = ", i);
		scanf("%d", &v[i]);
	}

	return v;
}


int main()
{
	int m, n,i,j;
	int *v1,*v2;
	int gasit;

	//Se vor citi doua numere m si n
	printf("m = ");
	scanf("%d", &m);

	printf("n = ");
	scanf("%d", &n);

	//vectorul cu m elemente
	printf("\nVectorul cu m elemente\n");
	v1 = citire(m);
	
	printf("\n\n");

	//vectorul cu n elemente
	printf("Vectorul cu n elemente\n");
	v2 = citire(n);

	printf("\n\n");

	for (j = 0; j < m; j++) {
		gasit = 0;

		// j = 0
		for (i = 0; i < n; i++) {
			if (v1[j] == v2[i])
				gasit = 1;
		}

		if (gasit) 
			printf("%d,", v1[j]);
	}

	printf("\n");

	free(v1,v2);

	system("pause");
	return 0;
}