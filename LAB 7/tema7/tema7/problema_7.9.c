/*Problema 7.9.
Se citesc de la tastatură cuvinte separate prin spaţii albe (spaţiu, tab sau enter). Pornind 
de la cuvintele citite, se construieşte un şir de caractere după următoarele reguli: 
•	Primul cuvânt citit se adaugă la şirul de caractere; 
•	Fiecare din următoarele cuvinte citite se adaugă la şirul de caractere dacă ultimele două litere ale şirului 
coincid cu primele două litere ale cuvântului (nu se face distincţie între literele mici şi cele mari); 
•	Cuvintele adăugate la şirul de caractere sunt despărţite de caracterul ’-’. 
Să se afişeze şirul astfel construit. 
Spre exemplu, pentru intrarea: Fazan Antic Noe icoana Egipt naftalina nimic Narcisa trei altceva santier iarba Caine Pisica erudit
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main() 
{
	char *sir, *aux, *auxfinal, c, *sirfinal;
	int n, nfinal, index = 0, i, incepesacaute = 0, adauga = 1;
	int v[2];

	sir = (char *)malloc(1);
	sirfinal = (char *)malloc(1);

	if (!sir) {
		printf("Nu pot aloca memorie pentru sirul vid.\n");
		exit(EXIT_FAILURE);
	}
	sir[0] = 0;

	n = 0;
	nfinal = 0;

	
	while ((c = getchar()) != EOF ) {

		aux = (char *)realloc(sir, n + 2);
		if (!aux) {
			free(sir);
			printf("Nu pot redimensiona blocul.\n");
			exit(EXIT_FAILURE);
		}
		else {
			sir = aux;
		}

		/* Plasam noul caracter la sfarsitul sirului. */
		sir[n] = c;
		

		/* Mutam terminatorul de sir cu o pozitie mai la dreapta fata de unde era pana acum. */
		sir[n + 1] = 0;


		/* Lungimea sirului creste cu 1. */
		n++;
	}

	
	// Adaugare in V
	for (i = 0; i < strlen(sir) - 1; i++) {

		if (isspace(sir[i])) {
			// Daca e spatiu
			incepesacaute = 1;
			adauga = 0;

		}
		else {
			// Daca nu e spatiu
			if (incepesacaute) {

				if (tolower(sir[i]) == tolower(v[0]) && tolower(sir[i + 1]) == tolower(v[1])) {
					adauga = 1;
				}
				incepesacaute = 0;
				
			}
			else {

				if (adauga) {
					v[0] = v[1];
					v[1] = sir[i];
				}
				
			}

		}


		if (adauga) {
			auxfinal = (char *)realloc(sirfinal, nfinal + 2);
			sirfinal = auxfinal;
			sirfinal[nfinal] = sir[i];
			sirfinal[nfinal + 1] = 0;
			nfinal++;
		}

		if (incepesacaute) {

			if (sirfinal[nfinal - 1] != '-') {
				auxfinal = (char *)realloc(sirfinal, nfinal + 2);
				sirfinal = auxfinal;
				sirfinal[nfinal] = '-';
				sirfinal[nfinal + 1] = 0;
				nfinal++;
			}

		}


	}

	printf("%s\n", sirfinal);

	free(sir);
	free(sirfinal);

	system("pause");
	return 0;
}


