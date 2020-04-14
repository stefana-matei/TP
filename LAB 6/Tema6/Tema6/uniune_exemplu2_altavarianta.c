#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>



struct Produs {
	char nume[20];  Ca orice structură, Produs mai poate conține și alte câmpuri, în afară de uniune și de selectorul său. 
	double pret;    De exemplu, putem să adăugăm câmpuri care sunt comune pentru orice fel de produs
	char Unitate_masura;	  unitate de masura: 'b'-la bucata, 'k'-kg
	union {
		int numar_bucati;
		double cantitate_in_kg;
	}cantitate;	  cantitate
};


void afisare(struct Produs *persoana)
{
	switch (persoana->Unitate_masura) {
	case 'b':
		printf("%s | %.2lf lei | %d bucati\n", persoana->nume, persoana->pret, persoana->cantitate.numar_bucati);
		break;
	case 'k':
		printf("%s | %.2lf lei/kg | %g kg\n", persoana->nume, persoana->pret, persoana->cantitate.cantitate_in_kg);
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
		printf("Produs : ");
		scanf("%s", persoana->nume);

		printf("Pret : ");
		scanf("%lf", &persoana->pret);

		printf("numar de bucati: ");
		scanf("%d", &persoana->cantitate.numar_bucati);
		break;
	case 'k':
		printf("Produs : ");
		scanf("%s", persoana->nume);

		printf("Pret : ");
		scanf("%lf", &persoana->pret);

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
