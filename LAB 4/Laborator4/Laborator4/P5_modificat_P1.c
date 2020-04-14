/*Sa se modifice P1 astfel incat la adaugarea unui produs, daca numele respectiv exista deja in baza de date, 
acesta sa nu mai fie adaugat ci sa fie schimbat pretul vechi cu cel nou introdus.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char nume[50];
	float pret;
} produse;

int produs_deja_existent(char produs[50], produse *stock, int n) 
{
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(stock[i].nume, produs) == 0) {
			return i;
		}
	}
	return -1;
}

int main()
{
	produse prds[100];
	int i,optiune, n = 0,index;
	char nume_produs[50];

	while (1) {
		printf("1.Adaugare  ");
		printf("\n2.Afisare ");
		printf("\n0.Iesire \n\n");
		printf(" Optiunea dvs : ");
		scanf("%d", &optiune);
		printf("\n");
		switch (optiune) {
		case 1:
			getchar();
			printf("Nume : ");
			gets(nume_produs);
			index = produs_deja_existent(nume_produs, prds, n);

			if (index >= 0) {
				printf("Produsul este deja in baza de date!\n");
				printf("Noul pret: "); 
				scanf("%g", &prds[index].pret);
				n--;
			}
			else {
				strcpy(prds[n].nume, nume_produs);
				printf("Pret: "); 
				scanf("%g", &prds[n].pret);
			}
			n++;
			printf("\n");
			break;
		case 2:
			for (i = 0; i < n; i++) {
				printf("%s %g\n", prds[i].nume, prds[i].pret);
			}
			break;
		case 0: exit(0);
			break;
		default:
			printf("\Optiunea nu exista!\n");
			break;
		}
	}

	system("pause");
	return 0;
}