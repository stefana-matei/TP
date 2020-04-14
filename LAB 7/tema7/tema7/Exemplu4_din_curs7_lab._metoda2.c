/*Exemplu: Se citesc m și n. Folosind doar cantitatea necesară de memorie, se citesc elementele unei matrici a[m][n].
Se cere să se afișeze maximul fiecărei coloane.*/

/*METODA 2-----------A doua metodă de alocare a unei matrici este să folosim un vector de pointeri, fiecare pointer pointând la câte o linie din matrice.
În acest caz liniile vor fi alocate separat, ca blocuri de memorie independente.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int m, n, i, j;
	int **a;		// matricea este implementata ca un vector de pointeri la liniile ei

	printf("Se citesc numarul de linii si coloane a matricei : ");

	printf("\n\nm = ");
	scanf("%d", &m);		//m-numar linii 

	printf("n = ");
	scanf("%d", &n);		//n-numar coloane


	// alocare vector de pointeri la linii
	if ((a = (int**)malloc(m * sizeof(int*))) == NULL) {
		printf("memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}


	// alocare linii
	for (i = 0;i < m;i++) {
		if ((a[i] = (int*)malloc(n * sizeof(int))) == NULL) {
			for (i--;i >= 0;i--)
				free(a[i]);			 // elibereaza liniile alocate anterior
			free(a);			 // elibereaza vectorul de pointeri
			printf("memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}
	}


	printf("\n");
	//citire elementele matricei
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	printf("\n");
	//afisare matrice
	for (i = 0;i < m;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf("\t%d", a[i][j]);
		}
	}

	printf("\n");


	// cauta maximul fiecarei coloane
	// parcurgea se face in ordinea coloanelor
	for (j = 0;j < n;j++) {
		int max = a[0][j];

		// parcurge fiecare element din coloana j, incepand cu a doua linie
		for (i = 1;i < m;i++) {
			int aux = a[i][j];

			if (aux > max)
				max = aux;
		}

		printf("\nMaximul coloanei %d este: %d\n", j, max);
	}

	for (i = 0;i < m;i++)
		free(a[i]);		// elibereaza fiecare linie

	free(a);		 // elibereaza vectorul de linii

	system("pause");
	return 0;
}
