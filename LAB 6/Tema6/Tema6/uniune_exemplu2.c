#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

  cantitatea unui produs poate fi data in numar de bucati sau prin greutatea sa, exprimata in kg
union Cantitate {
	int numar_bucati;
	double cantitate_in_kg;
};

struct Produs {
	char Unitate_masura;	  unitate de masura: 'b'-la bucata, 'k'-kilograme
	union Cantitate cantitate;
};

void afisare(struct Produs *persoana)
{
	switch (persoana->Unitate_masura) {
	case 'b':
		printf("%d bucati\n", persoana->cantitate.numar_bucati);
		break;
	case 'k':
		printf("%g kg\n", persoana->cantitate.cantitate_in_kg);
		break;
	default:printf("unitate de masura invalida\n");
	}
}

void citire(struct Produs *persoana)
{
	printf("Unitate de masura (b sau k) : ");
	scanf("%c", &persoana->Unitate_masura);
	switch (persoana->Unitate_masura) {
	case 'b':
		printf("numar de bucati: ");
		scanf("%d", &persoana->cantitate.numar_bucati);
		break;
	case 'k':
		printf("greutate (kg): ");
		scanf("%lg", &persoana->cantitate.cantitate_in_kg);
		break;
	default:printf("unitate de masura invalida\n");
	}
}

int main()
{
	struct Produs persoana;
	citire(&persoana);
	afisare(&persoana);

	system("pause");
	return 0;
}
