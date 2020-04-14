#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>


typedef enum { Bucata, Kg }UnitateMasura;

struct Produs {
	char nume[20];
	double pret;
	UnitateMasura Unitate_masura;			  
	union {
		int numar_bucati;
		double kg;
	}cantitate;
};

void afisare(struct Produs *persoana)
{
	switch (persoana->Unitate_masura) {
	case Bucata:printf("%d bucati\n", persoana->cantitate.numar_bucati);break;
	case Kg:printf("%g kg\n", persoana->cantitate.kg);break;
	default:printf("unitate de masura invalida\n");
	}
}

void introducere(struct Produs *persoana)
{
	/*Deoarece tipul întreg corespunzător lui enum nu este specificat (compilatorul are latitudinea să folosească orice tip convenabil),
	in functie a trebuit folosită o variabilă auxiliară de tip cunoscut (int), pentru a se face corect citirea cu scanf.*/

	int Unitate_masura;		  variabila auxiliara folosita pentru citire, deoarece nu se stie dimensiunea tipului enum
	printf("unitate de masura (0-nr. bucati, 1-kilograme): ");
	scanf("%d", &Unitate_masura);
	persoana->Unitate_masura = Unitate_masura;		  copiere din variabila auxiliara in variabila de tip enum
	switch (persoana->Unitate_masura) {
	case Bucata:
		printf("numar de bucati: ");
		scanf("%d", &persoana->cantitate.numar_bucati);
		break;
	case Kg:
		printf("greutate (kg): ");
		scanf("%lg", &persoana->cantitate.kg);
		break;
	default:printf("unitate de masura invalida\n");
	}
}

int main()
{
	struct Produs persoana;
	introducere(&persoana);
	afisare(&persoana);

	system("pause");
	return 0;
}
