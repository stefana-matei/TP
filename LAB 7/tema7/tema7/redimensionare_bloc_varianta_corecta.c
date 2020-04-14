// Următorul program alocă iniţial un tablou de 100 de întregi, iar pe urmă îl redimensionează la 200 de întregi.

//	VARIANTA CORECTA A PROGRAMULUI ANTERIOR FOLOSIND VARIABILA AUXILIARA pentru a păstra adresa returnată de realloc

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 


int main() 
{
	int *a, *aux;

	/* Initial alocam memorie pentru 100 de intregi. */
	a = (int *)malloc(100 * sizeof(int));

	if (!a) {
		printf("Nu pot aloca memorie.\n");
		exit(EXIT_FAILURE);
	}

	/* Pe urma redimensionam blocul alocat la 200 de intregi.
	Pastram adresa returnata de realloc intr-un pointer auxiliar,
	pentru a nu-l suprascrie pe a. */
	aux = (int *)realloc(a, 200 * sizeof(int));


	/* Daca redimensionarea a esuat, eliberez blocul alocat initial,
	dupa care inchei programul cu mesaj de eroare. */
	if (!aux) {
		printf("Nu pot redimensiona blocul.\n");
		free(a); // blocul alocat initial
		exit(EXIT_FAILURE);
	}
	/*Daca aloc a reusit,copiez adresa din aux in a si continui executia. */
	else {
		a = aux;
	}


	/* Eliberez blocul la final. */
	free(a);

	system("pause");
	return 0;
}
