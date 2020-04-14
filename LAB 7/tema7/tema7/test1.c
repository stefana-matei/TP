/*Atentie: unele dintre programe pot fi scrise intenționat greșit, pentru a evidenția greșeli care se
 fac în mod tipic!*/

//TEST 1 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{
	int *x, *z;
	x = (int *)malloc(7 * sizeof(int));

	if (!x) {
		printf("Eroare alocare 1.\n");
		exit(EXIT_FAILURE);
	}

	z = (int *)malloc(24 * sizeof(int));

	if (!z) {
		printf("Eroare alocare 2.\n");
		free(x);
		exit(EXIT_FAILURE);
	}

	free(x);
	free(z);
	return 0;
}


//-VARIANTA CORECTATA??

/*int main() 
{
	int *x, *z;
	x = (int *)malloc(7 * sizeof(int));
	printf("blocul de memorie este plasat la adresa %p\n", x);

	if (x == NULL) {
		printf("Eroare alocare 1.\n");
		exit(EXIT_FAILURE);
	}

	z = (int *)malloc(24 * sizeof(int));
	printf("blocul de memorie este plasat la adresa %p\n", z);

	if (z == NULL) {
		printf("Eroare alocare 2.\n");
		exit(EXIT_FAILURE);
	}

	free(x);
	free(z);

	system("pause");
	return 0;
}*/

