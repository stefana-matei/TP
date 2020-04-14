/*Următorul program alocă iniţial un tablou de 100 de întregi, iar pe urmă îl redimensionează la 200 de întregi.*/

// programul  nu este 100% corect

#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int *a;

	/* Initial alocam memorie pentru 100 de intregi. */
	a = (int *)malloc(100 * sizeof(int));

	if (!a) {
		printf("Nu pot aloca memorie.\n");
		exit(EXIT_FAILURE);
	}


	/* Pe urma redimensionam blocul alocat la 200 de intregi. */
	a = (int *)realloc(a, 200 * sizeof(int));

	if (!a) {
		printf("Nu pot redimensiona blocul.\n");
		exit(EXIT_FAILURE);
	}


	/* Eliberez blocul la final. */
	free(a);
	return 0;
}
