/*Problema 7.5
Să se citească datele(numele şi vârsta) despre un număr oarecare n de persoane şi să se memoreze într-o structură. 
Să se găsească o structură de date adecvată, astfel încât consumul de memorie să fie optim. 

Se defineşte tipul structurat persoana:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct{
	 char*nume;
	 int varsta;
}persoana;

int n;
persoana*tab;

void citire(void) 
{
	int i;
	char buf[80];

	printf("Introduceti numarul de persoane : \n");
	scanf("%d", &n);

	if (!(tab = (persoana*)malloc(n * sizeof(persoana)))) {
		printf("Eroare alocare dinamica memorie!\n");
		exit(1);
	}

	for (i = 0;i < n;i++) {
		printf("Introduceti numele persoanei : ");
		scanf("%s", buf);

		if (!(tab[i].nume = (char*)malloc(strlen(buf) + 1))) {
			printf("Eroare alocare dinamica memorie!\n");
			exit(1);
		}
		strcpy(tab[i].nume, buf);

		printf("Introduceti varsta persoanei : ");
		scanf("%d", &tab[i].varsta);
	}
}


int main() 
{
	citire();
	free(tab);
	system("pause");
	return 0;

}