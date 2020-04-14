/*. O structura contine ora (intreg) la care s-a masurat o anumita temperatura si valoarea acestei temperatori (real). 
Se cere n<=10 si apoi n temperaturi. Se cere apoi o ora de inceput si una de sfarsit. 
Sa se afiseze media temperaturilor care au fost masurate in acel interval orar, inclusiv in capetele acestuia*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int ora;
	float temp;
}temperaturi;

void adaugare(temperaturi *t, int n)
{
	printf("Ora:");
	scanf("%d", &((t + n)->ora));

	printf("Temperaura:");
	scanf("%f", &((t + n)->temp));

	printf("\n");
}

void medie(temperaturi *t, int n, float st, float en)
{
	int i, nr = 0;
	float m = 0;
	for (i = 0;i < n;i++)
		if (((t + i)->ora) <= en && ((t + i)->ora) >= st)
		{
			m += ((t + i)->temp); nr++;
		}
	m /= nr;
	printf("%f", m);
}

int main()
{
	temperaturi t[100];
	int n, i;
	float oi, os;

	printf("Temperaturi : ");
	scanf("%d", &n);
	printf("\n");

	printf("Ora de inceput : ");
	scanf("%f", &oi);
	printf("\n");

	printf("Ora de sfarsit : ");
	scanf("%f", &os);
	printf("\n");

	do
	{
		printf("1. Adaudare:\n");
		printf("2. Afisare media:\n\n");
		printf("Optiunea : ");
		scanf("%d", &i);
		printf("\n");

		switch (i)
		{
		case 1:
			for (i = 0;i < n;i++)
				adaugare(t, i);
			break;
		case 2:medie(t, n, oi, os);
			printf("\n\n");
			break;
		default:i = 0;
			break;
		}
	} while (i != 0);


	system("pause");
	return 0;
}