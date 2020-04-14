/*
O matrice rară (contine 90% din elemente 0) este păstrată economic sub forma unei structuri, care conţine următoarele câmpuri:
int l,c - numărul de linii/coloane al matricei rare;
int n - numărul de elemente nenule
int linii[] - vectorul ce păstrează liniile în care se află elemente nenule
int coloane[] - vectorul ce păstrează coloanele în care se află elemente nenule
float nenul[] - vectorul ce păstrează elementele nenule

Să se definească funcţii pentru:
•	citirea unei matrice rare;
•	afişarea unei matrice rare (ca o matrice, cu tot cu zerouri)
•	adunarea a două matrice rare.
Observatii :
Vectorii linii[], coloane[], nenule[] vor avea fiecare cate n elemente.
Elementul nenul cu valoare nenule[index] se afla pe linia linii[index] si coloana coloane[index].
Elementele vor fi citite in ordinea crescatoare a liniilor, iar elementele de pe aceeasi linie in ordinea crescatoare a coloanelor.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#define MAX 100 
#define N 30

typedef struct {
	int l, c, linii[MAX], coloane[MAX], n;
	float numere_nenule[MAX];
}matrice;


typedef struct {
	int e_linie, e_coloana;
	float element;
}element;

element el[N];
element el0[N];

void citire(matrice m)
{
	int i = 0, j = 0, aux, index = -1, validate = 0, count = 0;
	float e;

	//numărul de elemente nenule
	printf("Introduceti numarul de elemente nenule : ");
	scanf("%d", &m.n);
	printf("\n");

	while (validate < m.n) {
		scanf("%f", &e);
		printf("\n");
		validate++;
		if (e == 0) {   //daca elementul este nul,incrementam j(pentru coloana) si crestem counterul de nule
			count++;
			if (j <= m.c && i <= m.l && j != m.c - 1)
				j++;
			else if (j == m.c - 1 && i != m.l) {
				j = 0;
				i++;
			}
		}
		else {   //daca elementul este diferit de zero ii salvam indicii pentru viitoarea matrice i si j

			index++;
			m.coloane[index] = j;
			m.linii[index] = i;
			m.numere_nenule[index] = e;

			if (j <= m.c && i <= m.l && j != m.c - 1)
				j++;
			else if (j == m.c - 1 && i != m.l) {
				j = 0;
				i++;
			}
			//salvam valoarea elementului nenul
		}


	}


	//vectorul ce păstrează liniile în care se află elemente nenule
	printf("Introduceti liniile cu elemente nenule : \n ");
	for (i = 0;i < m.n;i++)
		scanf("%d", &m.linii[i]);
	printf("\n");

	//vectorul ce păstrează coloanele în care se află elemente nenule
	printf("Introduceti coloanele cu elemente nenule :  \n");
	for (i = 0;i < m.n;i++)
		scanf("%d", &m.coloane[i]);


	for (aux = 0;aux <= index;aux++) {
		el[aux].e_linie = m.linii[aux];
		el[aux].e_coloana = m.coloane[aux];
		el[aux].element = m.numere_nenule[aux];
	}
	printf("\n");
}

void afisare_matrice(matrice m)
{
	int i, j, index = 0;

	for (i = 1;i <= m.l;i++) {
		printf("\n");
		for (j = 1;j <= m.c;j++) {
			if (i == el[index].e_linie && j == el[index].e_coloana) {
				printf(" %.1f ", el[index].element);
				index++;
			}
			else
				printf(" 0.0 ");
		}
	}
	printf("\n");
}

void suma(matrice m, matrice n)
{
	int i, j, index0 = 0, index = 0;

	for (i = 0;i < m.l;i++) {
		printf("\n");
		for (j = 0;j < m.c;j++) {
			//daca elementele din ambele matrici sunt nenule,afisam suma lor
			if (i == el0[index0].e_linie && j == el0[index0].e_coloana && i == el[index].e_linie && j == el[index].e_coloana) {
				printf(" %.1f ", el0[index0].element + el[index].element);
				index0++;
				index++;
			}

			//daca doar un element este nenul,il afisam pe acesta
			else if (i == el0[index0].e_linie && j == el0[index0].e_coloana) {
				printf(" %.1f ", el0[index0].element);
				index0++;
			}

			else if (i == el[index].e_linie && j == el[index].e_coloana) {
				printf(" %.1f ", el[index].element);
				index++;
			}

			//daca ambele sunt nule,afisam 0
			else
				printf(" 0.0 ");
		}
	}

	printf("\n");

}

int main()
{
	matrice m, n;
	int optiune, i;
	do {
		printf("1.Introduceti matricea .\n");
		printf("2.Afisati matricea .\n");
		printf("3.Adunare a doua matrici .\n");
		printf("0.Iesire .\n");
		printf("Optiunea dvs. este : ");
		scanf("%d", &optiune);
		printf("\n");
		switch (optiune) {
		case 0:exit(0);
			break;
		case 1:
			//numărul de linii al matricei rare
			printf("Introduceti numarul de linii :  ");
			scanf("%d", &m.l);
			printf("\n");


			//numărul de coloane al matricei rare
			printf("Introduceti numarul de coloane :  ");
			scanf("%d", &m.c);
			printf("\n");

			citire(m);
			break;
		case 2:
			printf("Matricea este : \n");
			afisare_matrice(m);
			break;
		case 3:
			printf("Introduceti numarul de linii ale celor doua matrici : ");
			scanf("%d", &m.l);
			n.l = m.l;

			printf("Introduceti numarul de coloane ale celor doua matrici : ");
			scanf("%d", &m.c);
			n.c = m.c;

			printf("Introduceti prima matrice : \n");
			citire(m);
			afisare_matrice(m);
			for (i = 0;i < N;i++)
				el0[i] = el[i];

			printf("Introduceti cea de-a doua  matrice : \n");
			citire(n);
			afisare_matrice(n);

			printf("Suma matricelor este : \n");
			suma(m, n);
			break;
		default:
			printf("Optiunea nu exista!\n");
			break;
		}

	} while (optiune != 0);

	system("pause");
	return 0;
}

