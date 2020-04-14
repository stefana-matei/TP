#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef enum { gram, metru, litru } Unitate_masura;
typedef enum { deci, centi, mili, nano, pico, deca, hecto, kilo, mega, giga } Multiplicator;

struct masuratoare
{
	unsigned int nr;
	Unitate_masura um;
	Multiplicator multi;
};

void citire(struct masuratoare *m)
{
	int unitate_masura;
	printf("Scrieti o valoare : ");
	scanf("%u", &m->nr);
	printf("Unitatea de masura(0-gram,1-metru,2-litru):");
	scanf("%d", &unitate_masura);
	m->um = unitate_masura;
}

void afisare(struct masuratoare *m)
{
	//daca unitatea de masura este gram
	if (m->um == 0){
		int multi;
		printf("%u grame", m->nr);
		multi = m->nr;
		if (multi >= 10 && multi < 100)
		{
			multi = multi / 10;
			printf("=>%d decagrame\n", multi);
		}
		else
			if (multi >= 100 && multi < pow(10, 3))
			{
				multi = multi / 100;
				printf("=>%d hectograme\n", multi);
			}
			else
				if (multi >= pow(10, 3) && multi < pow(10, 6))
				{
					multi = multi / pow(10, 3);
					printf("=>%d kilograme\n", multi);
				}
				else
					if (multi >= pow(10, 6) && multi < pow(10, 9))
					{
						multi = multi / pow(10, 6);
						printf("=>%d megagrame\n", multi);
					}
					else
						if (multi >= pow(10, 9) && multi < pow(10, 10))
						{
							multi = multi / pow(10, 9);
							printf("=>%d gigagrame\n", multi);
						}
						else
							printf("=>Eroare!\n");
	}else if (m->um == 1) { 	//daca unitatea de masura este metru
		printf("%d metri", m->nr);
		int multi;
		multi = m->nr;
		if (multi >= 10 && multi < 100)
		{
			multi = multi / 10;
			printf("=>%d decametri\n", multi);
		}
		else
			if (multi >= 100 && multi < pow(10, 3))
			{
				multi = multi / 100;
				printf("=>%d hectometri\n", multi);
			}
			else
				if (multi >= pow(10, 3) && multi < pow(10, 6))
				{
					multi = multi / pow(10, 3);
					printf("=>%d kilometri\n", multi);
				}
				else
					if (multi >= pow(10, 6) && multi < pow(10, 9))
					{
						multi = multi / pow(10, 6);
						printf("=>%d megametri\n", multi);
					}
					else
						if (multi >= pow(10, 9) && multi < pow(10, 10))
						{
							multi = multi / pow(10, 9);
							printf("=>%d gigametri\n", multi);
						}
						else
							printf("=>Eroare!\n");
	}
	else {
		printf("%d litri", m->nr);
		int multi;
		multi = m->nr;
		if (multi >= 10 && multi < 100)
		{
			multi = multi / 10;
			printf("=>%d decalitri\n", multi);
		}
		else
			if (multi >= 100 && multi < pow(10, 3))
			{
				multi = multi / 100;
				printf("=>%d hectolitri\n", multi);
			}
			else
				if (multi >= pow(10, 3) && multi < pow(10, 6))
				{
					multi = multi / pow(10, 3);
					printf("=>%d kilolitri\n", multi);
				}
				else
					if (multi >= pow(10, 6) && multi < pow(10, 9))
					{
						multi = multi / pow(10, 6);
						printf("=>%d megalitri\n", multi);
					}
					else
						if (multi >= pow(10, 9) && multi < pow(10, 10))
						{
							multi = multi / pow(10, 9);
							printf("=>%d gigalitri\n", multi);
						}
						else
							printf("=>Eroare!\n");
	}
}

int main()
{
	struct masuratoare m;
	printf("Dimensiune: %d\n", sizeof(struct masuratoare));
	citire(&m);
	printf("\n");
	afisare(&m);
	printf("\n");

	system("pause");
	return 0;
}
