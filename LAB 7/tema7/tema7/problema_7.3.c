/*Aplicația 7.3: Să se scrie o funcție care primește două șiruri de caractere și le concatenează cu un spațiu între ele, 
folosind un bloc de memorie alocat dinamic pentru rezultat.
Funcția va returna acest bloc de memorie. 
Să se verifice funcția cu două șiruri de caractere introduse de la tastatură, fiecare de maxim 100 de caractere.*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *p;

char concatenare(char sir1[], char sir2[])
{
	size_t size1, size2;

	sir1[strcspn(sir1, "\n")] = '\0';   // sterge posibilul \n final
	sir2[strcspn(sir2, "\n")] = '\0';   // sterge posibilul \n final

	size1 = strlen(sir1) + 1; // nr de caractere total, inclusiv terminatorul
	size2 = strlen(sir2) + 1; // nr de caractere total, inclusiv terminatorul


	if ((p = (char*)malloc((size1 + size2) * sizeof(char))) == NULL) {
		printf("Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}

	strcat(sir1, " ");
	strcat(sir1, sir2);		//concatenarea sirurilor introduse de la tastatura

	strcpy(p, sir1);

	printf("\n%s\n", p);	//afisarea sirurilor concatenate

	return p;		//returneaza  blocul de memorie.

}


int main()
{
	char sir1[100], sir2[100];

	fgets(sir1, 100, stdin);
	fgets(sir2, 100, stdin);

	concatenare(sir1, sir2);

	free(p);
	system("pause");
	return 0;



}