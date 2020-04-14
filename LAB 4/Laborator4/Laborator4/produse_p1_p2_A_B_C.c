/*P1. Sa se creeze o baza de date cu produse definite prin nume si pret.
Operatiile necesare sunt introducere si afisare si ele se vor da pe rand de la tastatura, 
utilizatorului fiindu-i prezentat un meniu de unde poate alege operatia dorita.

P2. 
A) Realizati apoi operatia de cautare de produs dupa nume. Acesta va fi introdus de la tastatura.
Daca s-a gasit produsul, se va afisa pretul sau. Daca nu s-a gasit, se va afisa mesajul „Nu exista”.

B) eliminati produsele gasite in cautarea dupa nume.

C)Ordonati produsele dupa pret, descrescator si afisati noua lista.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char nume[50];
	float pret;
}Produs;

int main() 
{
	Produs produse[100];
	int i, j, optiune, n = 0, ok, k, aux;
	char nume[20];

	while (1) {
		printf("1. Introducere  \n");
		printf("2. Afisare  \n");
		printf("3.Stergere  \n");
		printf("4.Cautare  \n");
		printf("5.Sortare descrescatoare \n");
		printf("0. Iesire\n");
		printf("Optiunea dvs. : ");
		scanf("%d", &optiune);
		printf("\n");
		switch (optiune) {
		case 1:
			getchar();
			printf("Nume : ");
			gets(produse[n].nume);
			printf("Pret : ");
			scanf("%f", &produse[n].pret);
			n++;

			printf("\n");
			break;
		case 2:
			for (i = 0;i < n;i++) {
				printf("%s %f\n", produse[i].nume, produse[i].pret);
			}
			printf("\n");
			break;
		case 3:     //stergere produse
			getchar();
			printf("Nume : ");
			gets(nume);
			for (i = 0;i < n;i++) {
				if (!strcmp(nume, produse[i].nume)) {
					for (j = i + 1;j < n;j++) {
						produse[j - 1] = produse[j];
					}
					n--;
					i--;
				}
			}
			break;
		case 4:     //cautare de produs dupa nume
			getchar();
			printf("Nume : ");
			gets(nume);
			ok = 0;
			for (i = 0; i < n; i++) {
				if (strcmp(produse[i].nume, nume) == 0) {
					printf("Produsul cautat : %s %f\n", produse[i].nume, produse[i].pret);
					ok = 1;
				}
			}

			if (ok == 0)
				printf("Nu exista!\n");

			printf("\n");
			break;
		case 5: //ordonati produsele dupa pret, descrescator si afisati noua lista.
			do
			{
				k = 1;
				for (i = 1; i < n; i++)
					if (produse[i - 1].pret  < produse[i].pret)

					{
						aux = produse[i].pret;
						produse[i].pret = produse[i - 1].pret;
						produse[i - 1].pret = aux;
						k = 0;
					}
			} while (!k);

			//afisare dupa sortarea produselor
			for (i = 0;i < n;i++) {
				printf("%s %f\n", produse[i].nume, produse[i].pret);
			}
			printf("\n");
			break;
		case 0:exit(0);
			break;
		default:printf("Optiunea dvs.nu exista!\n\n");
			break;

		}
	}

}