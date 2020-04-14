/*5) Să se scrie un program care sa administreze un parc de automobile. Informaţiile relative la un automobil sunt: numărul de locuri, puterea (în cai putere), marca, culoarea, anul fabricaţiei maşinii.
a) se vor citi informatiile relative la cele n automobile din parcul de autoturisme. Se vor afisa doar acele automobilele care au 5 locuri;
b) sa se ordoneze crescator dupa putere automobilele – se vor afisa datele ordonate;
c) sa se scrie o functie care afiseaza toate automobilele fabricate într-un anumit an dat ca parametru.*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>


typedef struct					
{
	char marca[20];
	char model[20];
	char culoare[20];
	int anul_fabricatiei;

	struct{			
		char numar_locuri;
		int putere;
	}date;					

}automobil;		


typedef automobil masini[20];	//tip de date propriu


void citire(masini a, int *n)			
{
	int i;
	printf("Dati numarul de automobile : ");
	scanf("%d", n);
	printf("\n");

	for (i = 0; i < *n; i++)
	{
		printf("Introduceti datele despre automobilul %d\n", i + 1);
		printf("\n");
		printf("Marca: ");
		scanf("%s", a[i].marca);
		printf("Modelul: ");
		scanf("%s", a[i].model);
		printf("Culoarea: ");
		scanf("%s", a[i].culoare);
		printf("Anul: ");
		scanf("%d", &a[i].anul_fabricatiei);
		printf("Numarul de locuri: ");
		scanf("%d", &a[i].date.numar_locuri);
		printf("Puterea in cai putere: ");
		scanf("%d", &a[i].date.putere);
		printf("\n");
	}
}

void afisare(masini a, int n)
{
	int i;
	for (i = 0;i < n;i++) {
		printf("Automobil [%d]:\n", i + 1);
		printf("\t->Marca:     %s\n", a[i].marca);
		printf("\t->modelul:   %s\n", a[i].model);
		printf("\t->culoarea:  %s\n", a[i].culoare);
		printf("\t->an fabr.:  %d\n", a[i].anul_fabricatiei);
		printf("\t->nr locuri: %d\n", a[i].date.numar_locuri);
		printf("\t->puterea:   %d\n\n", a[i].date.putere);

	}
}

void afisare_5_locuri(masini a, int n) //afisare doar acele automobilele care au 5 locuri
{
	int i;
	for (i = 0;i < n;i++) {
		if (a[i].date.numar_locuri == 5) {
			printf("Automobil [%d]:\n", i + 1);
			printf("\tmarca:     %s\n", a[i].marca);
			printf("\tmodelul:   %s\n", a[i].model);
			printf("\tculoarea:  %s\n", a[i].culoare);
			printf("\tan fabr.:  %d\n", a[i].anul_fabricatiei);
			printf("\tnr locuri: %d\n", a[i].date.numar_locuri);
			printf("\tputerea:   %d\n\n", a[i].date.putere);
		}

	}
}



void sortare_crescator_putere(masini a, int* n)
{
	int i, k;
	automobil aux;
	do {
		k = 1;
		for (i = 0; i <* n; i++)
		{
			if ((a[i-1].date.putere > a[i].date.putere))
			{
				aux = a[i];
				a[i] = a[i-1];
				a[i-1] = aux;
				k = 0;
			}
		}
	} while (!k);
}

void anul_fabricatiei(masini a, int n, int an_fabricatie)
{
	int i;
	for (i = 0;i < n ;i++)
	{
		if (a[i].anul_fabricatiei == an_fabricatie)			//atribuire valori membrilor structurii
		{
			printf("Automobil [%d]:\n", i + 1);
			printf("\tmarca:     %s\n", a[i].marca);
			printf("\tmodelul:   %s\n", a[i].model);
			printf("\tculoarea:  %s\n", a[i].culoare);
			printf("\tan fabr.:  %d\n", a[i].anul_fabricatiei);
			printf("\tnr locuri: %d\n", a[i].date.numar_locuri);
			printf("\tputerea:   %d\n\n", a[i].date.putere);
		}
	}
}

int main()
{
	masini a,aux;
	int n, anul_fabr;

	citire(a, &n);

	printf("Afisare doar cele  care au 5 locuri : \n");
	afisare_5_locuri(a, n);
	printf("\n");

	printf("Sortare crescatoare dupa  putere : \n\n");
	sortare_crescator_putere(a, &n);
	afisare(a, n); //afisarea masinilor crescator dupa putere
	
	printf("Se afiseaza toate automobilele fabricate într-un anumit an dat : ");
	scanf("%d", &anul_fabr);
	anul_fabricatiei(a, n, anul_fabr);
	printf("\n");

	system("pause");
	return 0;

}