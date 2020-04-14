/*Aplicația 7.2: Se citesc linii de caractere, până la întâlnirea liniei vide.
Să se sorteze aceste linii în ordine alfabetică și să se afișeze. Programul va utiliza doar strictul necesar de memorie.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *p;

void eliberare(char *vp[], int n)
{
	int i;
	for (i = 0;i < n;i++)
		free(vp[i]);   // elibereaza fiecare linie din linii
	free(vp);  // elibereaza vectorul in sine
}

int citire(char * vp[])
{
	int n = 0, stop;
	 char sir[80];
	size_t size;

	while (fgets(sir, 80, stdin)) {
		sir[strcspn(sir, "\n")] = '\0';   // sterge posibilul \n final
		size = strlen(sir) + 1;// lungimea sirului plus terminator

		if ((p = (char*)malloc(size * sizeof(char))) == NULL) {
			eliberare(p, size);
			printf("memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}

		strcpy(p, sir);
		vp[n] = p;
		++n;  //crestem numarul liniilor

		stop = size - 1;

		if (stop == 0)
			break;
	}

	return n;
}


void afisare(char *vp[], int n) {
	int i;

	for (i = 0; i < n; i++) {
		printf("%s\n", vp[i]);
	}
}


void sortare_alfabetica(char *vp[], int n) {
	int i, j;
	char *tmp;

	for (j = 1; j < n; j++) {
		for (i = 0; i < n - 1; i++) {
			if (strcmp(vp[i], vp[i + 1]) > 0) {
				tmp = vp[i];
				vp[i] = vp[i + 1];
				vp[i + 1] = tmp;
			}
		}
	}
}



int main(void)
{
	int n;
	char *vp[1000]; // vector de pointeri, cu dimensiune fixa

	n = citire(vp); // citire siruri si creare vector

	sortare_alfabetica(vp, n); // ordonare vector

	printf("\nLiniile sortare alfabetic : ");
	afisare(vp, n); // afisare siruri
	printf("\n\n");

	free(p);
	system("pause");
	return 0;
}
