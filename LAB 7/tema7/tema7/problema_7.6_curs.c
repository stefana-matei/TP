/*Să se scrie un program care gestionează date despre un grup de studenţi. Pentru fiecare student se memorează
 Numele şi numărul matricol. Programul trebuie să implementeze următoarele operaţii: 
-citirea numărului de studenţi şi a datelor acestora; 
-afişarea datelor tuturor studenţilor; 
-sortarea listei de studenţi în ordinea alfabetică a numelor; 
-sortarea listei de studenţi în ordinea crescătoare a numerelor matricole;
 -căutarea unui student pentru care se precizează numele şi afişarea poziţiei pe care o ocupă acesta în lista
 ordonată alfabetic după numele studenţilor; 
-căutarea unui student pentru care se precizează numărul matricolşi afişarea poziţiei pe care o ocupă 
acesta în lista ordonată crescător după numărul matricol al studenţilor;
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
	char *nume;
	int numar;
}student;

student *tab;

int citire() 
{
	int n, i;
	char aux[80];

	printf("Numarul de studenti : "); 
	scanf("%d", &n);
	if (!(tab = (student *)malloc(n * sizeof(student)))) {
		printf("Eroare alocare dinamica!\n");
		exit(1);
	}

	for (i = 0;i < n;i++) {
		printf("Introduceti numele studentului : \n");
		scanf("%s", &aux);
		if (!(tab[i].nume = (char *)malloc(strlen(aux) + 1))) {
			printf("Eroare alocare dinamica!\n");
			exit(1);
		}
		strcpy(tab[i].nume, aux);
		printf("Introduceti numarul matricol:");
		scanf("%d", &tab[i].numar);
	}
	return n;
}


void afisare(int n) {
	int i;
	for (i = 0;i < n;i++)
		printf("\n%s\n%d\n", tab[i].nume, tab[i].numar);
	printf("\n");
}


void sortare_alfabetica(int n) 
{
	int i, k;
	student aux;
	do {
		k = 1;
		for (i = 0;i < n - 1;i++)
			if (strcmp(tab[i].nume, tab[i + 1].nume) > 0)
			{
				aux = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aux;
				k = 0;
			}
	} while (!k);
}


void sortare_crescatoare(int n) 
{
	int i, k;
	student aux;
	do {
		k = 1;
		for (i = 0;i < n - 1;i++)
			if (tab[i].numar > tab[i + 1].numar)
			{
				aux = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aux;
				k = 0;
			}
	} while (!k);

}


void cautare_nume(int n, char numele[20]) 
{
	int i;
	for (i = 0;i < n;i++)
		if (strcmp(tab[i].nume, numele) == 0)
			printf("Studentul cautat se afla pe pozitia %d\n", i);
}


void cautare_numar(int n, int nr) 
{
	int i;
	for (i = 0;i < n;i++)
		if (tab[i].numar == nr)
			printf("Studentul cautat se afla pe pozitia %d\n", i);
}


int main() 
{
	int n, nr;
	char nu[80];

	n = citire();
	printf("Lista initiala:\n");
	afisare(n);

	printf("Lista dupa sortarea alfabetica a numelui:\n");
	sortare_alfabetica(n);
	afisare(n);

	printf("Lista dupa sortarea crescatoare a numerelor matricole:\n");
	sortare_crescatoare(n);
	afisare(n);

	printf("Numele studentului cautat:");
	scanf("%s", &nu);
	sortare_alfabetica(n);
	cautare_nume(n, nu);

	printf("Numarul matricol cautat:");
	scanf("%d", &nr);
	sortare_crescatoare(n);
	cautare_numar(n, nr);

	free(tab);

	system("pause");
	return 0;
}