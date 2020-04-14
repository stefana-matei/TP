/*Exemplu: Se citesc m și n. Folosind doar cantitatea necesară de memorie, se citesc elementele unei matrici a[m][n]. 
Se cere să se afișeze maximul fiecărei coloane.*/


/*METODA 1 ----În prima variantă, alocăm matricea ca pe un vector care conține toate elementele, la fel cum face și compilatorul. 
Elementele vor fi stocate în memorie linie după linie.*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int m, n, i, j;
	int *a;		// matricea este implementata ca un vector ce contine toate elementele

	printf("Se citesc numarul de linii si coloane a matricei : ");

	printf("\n\nm = ");
	scanf("%d", &m);		//m-numar linii 

	printf("n = ");		
	scanf("%d", &n);		//n-numar coloane


	// alocare matrice
	if ((a = (int*)malloc(m*n * sizeof(int))) == NULL) {
		printf("memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}

	printf("\n");
	//citire elementele matricei
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i*n + j]);
		}
	}


	printf("\n");
	//afisare matrice
	for (i = 0;i < m;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf("\t%d", a[i*n + j]);
		}
	}

	printf("\n");



	// cauta maximul fiecarei coloane
	// parcurgerea se face in ordinea coloanelor
	for (j = 0;j < n;j++) {
		int max = a[j];		// primul element de pe coloana j, din linia 0, adica: 0*n+j


		// parcurge fiecare element din coloana j, incepand cu a doua linie
		for (i = 1;i < m;i++) {
			int aux = a[i*n + j];
			if (aux > max)
				max = aux;
		}
		printf("\nMaximul coloanei %d este: %d\n", j, max);
	}

	printf("\n");

	// elibereaza memoria alocata pentru matrice
	free(a);

	system("pause");
	return 0;
}
