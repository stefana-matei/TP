/*Exemplu: 
	Se citesc linii de caractere, de maxim 200 de caractere fiecare, până la întâlnirea liniei vide.
Ulterior se cere un șir, terminat și el cu \n.
Să se afișeze toate liniile care conțin șirul dat. Programul va utiliza doar strictul necesar de memorie. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **linii = NULL;    // vector de linii
int nrLinii = 0;        // nr de linii din linii

void eliberare()
{
	int i;
	for (i = 0;i < nrLinii;i++)
		free(linii[i]);   // elibereaza fiecare linie din linii
	free(linii);  // elibereaza vectorul in sine
}

// citeste o linie de max 200 caractere si depune caracterele citite intr-un bloc alocat dinamic
// returneaza adresa blocului

char *linie()
{
	char buf[201];
	char *p;
	size_t n;
	fgets(buf, 201, stdin);
	buf[strcspn(buf, "\n")] = '\0';   // sterge posibilul \n final
	n = strlen(buf) + 1; // nr de caractere total, inclusiv terminatorul

	if ((p = (char*)malloc(n * sizeof(char))) == NULL) {
		eliberare();
		printf("memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	strcpy(p, buf);

	return p;
}

int main()
{
	char **linii2;
	char *p;
	int i;

	for (;;) {   
		// citeste pana la linia vida
		p = linie();
		if (strlen(p) == 0) {
			free(p); // elibereaza separat linia vida, deoarece ea nu se depune in linii
			break;
		}

		//realoca linii pentru o noua linie
		nrLinii++;
		if ((linii2 = (char**)realloc(linii, nrLinii * sizeof(char*))) == NULL) {
			eliberare();
			printf("memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}
		linii = linii2;
		linii[nrLinii - 1] = p;
	}


	printf("\nIntroduceti sirul de cautat : ");
	p = linie();
	// afiseaza toate liniile care contin sirul dat
	for (i = 0;i < nrLinii;i++) {
		if (strstr(linii[i], p))
			printf("%s\n", linii[i]);
	}

	free(p);
	eliberare();

	system("pause");

	return 0;
}
