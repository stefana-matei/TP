﻿/*	Următorul program declară o variabilă întreagă şi un tablou
de 5 întregi şi afişează adresele de memorie la care sunt plasate în memorie.*/

//Progarmul poate fi rescris astfel încât
 //să solicite spaţiu din zona dinamică pentru tabloul v.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 


int main()
{
	/* De data asta v este un pointer. */
	int n, *v;

	/* Urmarim dimensiunile si adresele variabilelor.
	Atat n cat si v sunt plasate in zona statica. */
	printf("variabila n are dimensiunea %d\n", sizeof(n));
	printf("variabila n este plasata la adresa %p\n", &n); //%p pentru a arata adresa
	printf("variabila v are dimensiunea %d\n", sizeof(v));
	printf("variabila v este plasata la adresa %p\n", &v);


	/* Cerem un bloc de memorie din zona dinamica.
	Solicitam un bloc de 5*4=20 de octeti,
		iar adresa o pastram in pointerul v. */
	v = (int *)malloc(5 * sizeof(int));
	printf("blocul de memoria este plasat la adresa %p\n", v);


	/* Daca malloc a returnat NULL, inseamna ca nu mai este spatiu
		in zona de memorie dinamica. In acest caz incheiem executia. */
	if (v == NULL) {
		printf("Nu pot aloca memorie.\n");
		exit(EXIT_FAILURE);
	}


	/* Daca am ajuns aici, alocarea a reusit.
	Pot folosi blocul alocat prin intermediul pointer-ului v, ca pe un tablou oarecare. */
	for (n = 0; n < 5; n++)
		v[n] = n;

	/* La final eliberez blocul de memorie. */
	free(v);

	system("pause");
	return 0;
}
