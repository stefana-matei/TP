/*	Ca prim exemplu de utilizare al alocării dinamice, să rezolvăm următoarea problemă:
 se citeşte de la tastatură un număr n, urmat de n numere reale. Cele n numere reale se vor memora într-un tablou. 
La final se mai citeşte un număr real x. Să se afişeze acele numere din tablou care se află în 
intervalul deschis (x-1,x+1). 
Problema se poate rezolva prin următorul program. Explicaţii suplimentare se găsesc sub formă de comentarii în cod. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
int main()
{
	float *a, x;
	int n, i;

	/* Citim n de la tastatura. */
	printf("Cate numere? ");
	scanf("%d", &n);
	printf("\n");

	/* Dupa ce il stim pe n, alocam din zona dinamica un bloc de memorie
	in care sa putem pastra n float-uri. */
	a = (float *)malloc(n * sizeof(float));


	/* Daca alocarea de memorie a esuat,
	incheiem executia cu mesaj de eroare. */
	if (!a) {
		printf("Nu se  poate aloca memorie!\n");
		exit(EXIT_FAILURE);
	}


	/* Daca am ajuns aici inseamna ca alocarea de memorie a reusit.
	Citim cele n numere reale. */
	for (i = 0; i < n; i++) {
		printf("a[%d]: ", i);
		scanf("%f", &a[i]);
	}

	printf("\n");

	/* Citim numarul x. */
	printf("x: ");
	scanf("%f", &x);

	/* Afisam numerele din intervalul cerut. */
	printf("Numerele din intervalul (%.2f, %.2f) sunt: ", x - 1, x + 1);
	for (i = 0; i < n; i++)
		if (fabs(x - a[i]) < 1) { //fabs este o functie ce returneaza valoarea absoluta,adica modulul deci va rezulta un nr pozitiv
			printf("%.2f  ", a[i]);
		}
	printf("\n");

	/* Obligatoriu eliberam blocul de memorie alocat dinamic. */
	free(a);

	system("pause");
	return 0;
}
