/*
Să se definească o structură de date pentru memorarea unor informații despre vehicule. Structura va folosi unde este posibil ,
pentru a minimiza memoria folosită. Un vehicul este definit prin:
	tipul motorului: benzină, motorină, electric
	marca: producător și tip (ex: Dacia Logan)
	tipul vehiculului: de persoane (se da numărul de locuri și de airbaguri), de marfă
(se dă capacitatea și dacă este frigorific sau nu) și special (se dă numele întrebuințării specifice, ex: ”tractor”).
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { TMBenzina, TMMotorina, TMElectric }TipMotor;
const char *numeTM[] = { "benzina", "motorina", "electric" };

typedef enum { TVPersoane, TVMarfa, TVSpecial }TipVehicul;
const char *nume_Tip_Vehicul[] = { "persoane", "marfa", "special" };

typedef struct {
	TipMotor tm;
	char marca[35];
	TipVehicul tv;
	union {

		struct {
			int nrLocuri;
			int nrAirbaguri;
		}p;

		struct {
			double capacitate;
			char frigorific;		 
		}m;

		char special[20];		  
	}specific;
}Vehicul;


void citire(Vehicul*v)
{
	int tm,tv;
	printf("Marca (producator si tip ) : ");
	gets(v->marca);

	printf("Tipul motorului (0-benzina, 1-motorina, 2-electric) : ");
	scanf("%d", &tm);
	v->tm = tm;

	printf("Tipul vehiculului (0-persoana, 1-marfa, 2-special) : ");
	scanf("%d", &tv);
	v->tv = tv;

	if (tv == 0) {
		printf("Numar de locuri : ");
		scanf("%d", &v->specific.p.nrLocuri);
		printf("Numar de airbaguri : ");
		scanf("%d", &v->specific.p.nrAirbaguri);
	}
	else if (tv == 1) {
		printf("Capacitate : ");
		scanf("%lf", &v->specific.m.capacitate);
		printf("Frigorific? (0 sau 1)  : ");
		scanf("%hhd", &v->specific.m.frigorific);
	}
	else {
		printf("Numele intrebuintarii specifice : ");
		scanf("%s", v->specific.special);
	}

	
}

void afisare(Vehicul*v)
{
	printf("\t Tip motor: %s\n", numeTM[v->tm]);
	printf("\tMarca : %s\n", v->marca);
	printf("\t Tip vehicul: %s\n", nume_Tip_Vehicul[v->tv]);

	if (v->tv == 0) {
		printf("\tNumar de locuri : %d\n", v->specific.p.nrLocuri);
		printf("\tNumar de airbaguri : %d\n", v->specific.p.nrAirbaguri);
	}
	else if (v->tv == 1) {
		printf("\tCapacitate : %.2lf\n ", v->specific.m.capacitate);
		printf("\tFrigorific : %hhd\n ", v->specific.m.frigorific);
	}
	else {
		printf("\tNumele intrebuintarii specifice : %s\n ", v->specific.special);
	}
	
	printf("\n");
}


int main()
{
	Vehicul v;
	int n;

	citire(&v);

	printf("\n\n");
	afisare(&v);

	system("pause");
	return 0;

}