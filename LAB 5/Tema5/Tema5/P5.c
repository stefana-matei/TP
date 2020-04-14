/* Să se scrie un program care gestionează date despre un grup de studenţi. Pentru fiecare student se memorează numele şi 
numărul matricol. Programul trebuie să implementeze următoarele operaţii:
- citirea numărului de studenţi şi a datelor acestora;
- afişarea datelor tuturor studenţilor;
- sortarea listei de studenţi în ordinea alfabetică a numelor;
- sortarea listei de studenţi în ordinea crescătoare a numerelor matricole;
- căutarea unui student pentru care se precizează numele şi afişarea poziţiei pe care o ocupă acesta în lista ordonată alfabetic după numele studenţilor;
- căutarea unui student pentru care se precizează numărul matricol şi afişarea poziţiei pe care o ocupă acesta în lista ordonată crescător după numărul matricol al studenţilor;

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct {
	char nume[20];
	int matricol;
}studenti;


void citire(studenti *s, int *n)
{
	(*n)++;
	fflush(stdin);
	printf("Introduceti numele studentului: ");
	fflush(stdin);
	scanf("%s", (s + *n)->nume);
	printf("Introduceti numarul matricol: ");
	scanf("%d", &s[*n].matricol);

	printf("\n");
}

void afisare(studenti s[], int n)
{
	printf("%s %d \n", (s + n)->nume, s[n].matricol);
	printf("\n");
}

void sortare_nume(studenti s[], int *n)
{
	int ordonat, i;
	studenti aux;

	do
	{
		ordonat = 1;
		for (i = 1;i <= *n;i++)
			if (strcmp((s + i - 1)->nume, (s + i)->nume) > 0)
			{
				aux = *(s + i - 1);
				*(s + i - 1) = *(s + i);
				*(s + i) = aux;
				ordonat = 0;
			}
	} while (!ordonat);

	for (i = 0;i <= *n;i++)
		afisare(s, i);
}

void sortare_numar(studenti s[], int *n)
{
	int ordonat, i;
	studenti aux;

	do {
		ordonat = 1;
		for (i = 1;i <= *n;i++)
			if (s[i - 1].matricol > s[i].matricol)
			{
				aux = *(s + i - 1);
				*(s + i - 1) = *(s + i);
				*(s + i) = aux;
				ordonat = 0;
			}

	} while (!ordonat);

	for (i = 0;i <= *n;i++)
		afisare(s, i);
}

void cautare_nume(studenti s[], int n, char nume[])
{
	int i, exista = 0;

	for (i = 0;i <= n;i++)
		if (strcmp((s + i)->nume, nume) == 0) {
			printf("Studentul %s se afla pe pozitia %d \n\n", (s + i)->nume, i + 1);
			exista = 1;
		}
		
	if (!exista )
		printf("Nu exista in baza de date!\n\n");

}

void cautare_numar(studenti s[], int n, int nr)
{
	int i, exista = 0;

	for (i = 0;i <= n;i++)
		if (s[i].matricol == nr) {
			printf("Studentul %s se afla pe pozitia %d \n\n", (s + i)->nume, i + 1);
			exista = 1;
		}
	if(!exista)
		printf("Nu exista in baza de date!\n\n");
		

}

int main()
{
	studenti s[30];
	int n = -1, i, optiune, nr;
	char nume[20];
	do {
		printf(" 1.Adaugare student \n 2.Afisare studenti \n 3.Ordonare alfabetica \n 4.Ordonare crescatoare numar matricol \n 5.Cautare nume \n 6.Cautare numar matricol \n Optiunea dvs. : ");
		scanf("%d", &optiune);
		printf("\n");
		switch (optiune)
		{
		case 1: citire(s, &n); 
			break;
		case 2: 
			for (i = 0;i <= n;i++)
			afisare(s, i);
			break;
		case 3: 
			sortare_nume(s, &n); 
			break;
		case 4: 
			sortare_numar(s, &n); 
			break;
		case 5: 
			printf("Introduceti numele pe care doriti sa-l cautati: ");
			scanf("%s", &nume);
			cautare_nume(s, n, nume);
			break;
		case 6: 
			printf("Introduceti numarul matricol pe care doriti sa-l cautati: ");
			scanf("%d", &nr);
			cautare_numar(s, n, nr);
			break;
		}
	} while (optiune < 7);



	system("pause");
	return 0;
}