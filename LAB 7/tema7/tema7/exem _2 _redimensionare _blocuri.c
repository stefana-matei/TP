/*	Un exemplu de utilizare a redimensionării de blocuri este următorul: 
Se citeşte de la tastatură un text până la apariţia lui EOF. Nu se ştie de la început ce lungime are textul. 
Scrieţi un program care foloseşte un şir alocat dinamic şi redimensionat după necesităţi pentru a păstra textul citit.
Programul trebuie să poată citi texte de orice lungime (mii, sute de mii de caractere), în limita memoriei dinamice disponibile. */

//	Exemplul 2 de utilizare a redimensionării de blocuri 
//	Programul care rezolvă problema, cu explicaţii sub formă de comentarii, este următorul: 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 


int main() 
{
	char *a, *aux;
	int c, n;


	/* Initial textul nostru este sirul vid, adica "". */
	a = (char *)malloc(1);
	if (!a) {
		printf("Nu pot aloca memorie pentru sirul vid.\n");
		exit(EXIT_FAILURE);
	}
	a[0] = 0;


	/* Initial lungimea sirului este 0. */
	n = 0;


	/* Intram intr-o bucla in care citim de la tastatura cate un caracter, pana la EOF. */
	while ((c = getchar()) != EOF) {
		/* Dimensiunea curenta a blocului este n+1 (adica lungimea sirului, plus 1 pentru terminatorul de sir).
		Redimensionam blocul la n+2 pentru a face loc pentru noul caracter citit. */
		aux = (char *)realloc(a, n + 2);
		if (!aux) {
			free(a);
			printf("Nu pot redimensiona blocul.\n");
			exit(EXIT_FAILURE);
		}
		else {
			a = aux;
		}


		/* Plasam noul caracter la sfarsitul sirului. */
		a[n] = c;


		/* Mutam terminatorul de sir cu o pozitie mai la dreapta fata de unde era pana acum. */
		a[n + 1] = 0;


		/* Lungimea sirului creste cu 1. */
		n++;
	}


	/* La final afisam sirul. */
	printf("%s", a);


	/* Si eliberam memoria alocata dinamic. */
	free(a);

	system("pause");
	return 0;
}
