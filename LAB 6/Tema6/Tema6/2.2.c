/*Aplicația 2.2: Folosind struct și union, definiți o structură de date care să poată memora următoarele informații despre viețuitoare:
•	tipul (poate fi: mamifer, insectă, pește, pasăre)
•	durata medie de viață în ani
•	dacă e mamifer: perioada de gestație, numărul mediu de pui pe care îi naște
•	dacă e insectă: numărul de picioare, dacă poate să zboare sau nu, dacă este periculoasă sau nu pentru om
•	dacă e pește:  tipul de apă: sărată/dulce, adâncimea maximă la care se poate întâlni, viteza maximă de înot
•	dacă e pasăre: anvergura aripilor, altitudinea maximă de zbor, viteza maximă de zbor
Definiți structura în așa fel încât memoria consumată să fie minimă. Citiți și afișați informațiile despre o viețuitoare.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef enum { sarata, dulce }tip_apa;

typedef struct {
	unsigned int perioada_gestatie : 4;
	unsigned int numar_mediu_pui : 11;
}mamifer;

typedef struct {
	unsigned int numar_picioare : 10;
	unsigned int zboara : 1;
	unsigned int periculoasa : 1;
}insecta;

typedef struct {
	tip_apa tip : 1;
	unsigned int adancime_maxima : 9;
	unsigned int viteza_maxima : 7;
}peste;

typedef struct {
	unsigned int anvergura : 9;
	unsigned int altitudine_max :11;
	unsigned int viteza_maxima : 9;
}pasare;

typedef union {
	mamifer m;
	insecta i;
	peste pe;
	pasare pa;
}TIP;

struct {
	unsigned int durata_viata_medie : 7;
	unsigned int tip : 3;
	TIP t;
}s;

int main()
{
	unsigned int aux, durata_viata_medie;

	printf("Tip vietuitoare : \n");
	printf("(1) Mamifer\t(2) Insecta\t(3) Peste\t(4) Pasare : ");
	scanf("%d", &aux);
	s.tip = aux;

	printf("\n");

	if (aux >= 1 && aux <= 4) {
		printf("Durata medie de viata: "); 
		scanf("%d", &durata_viata_medie);
		s.durata_viata_medie = durata_viata_medie;

		switch (s.tip) {
		case 1:  //Mamifer
			printf("Perioada de gestatie: ");
			scanf("%d", &aux);
			s.t.m.perioada_gestatie = aux;
			printf("Numarul mediu de pui pe care-l naste: "); 
			scanf("%d", &aux);
			s.t.m.numar_mediu_pui = aux;
			break;


		case 2:  //Insecta
 			printf("Numarul de picioare: ");
			scanf("%d", &aux);
 			s.t.i.numar_picioare = aux;
 			printf("Poate sa zboare?\t(0) Nu  (1) Da : "); 
			scanf("%d", &aux);
 			s.t.i.zboara = aux;
 			printf("Este periculoasa pentru om?\t(0) Nu  (1) Da : ");
			scanf("%d", &aux);
 			s.t.i.periculoasa = aux;
 			break;


 		case 3:  //Peste
 			printf("Tipul de apa : \t(0) Sarata  (1) Dulce: "); 
			scanf("%d", &aux);
 			s.t.pe.tip = aux;
 			printf("Adancimea maxima la care se poate intalni: ");
			scanf("%d", &aux);
 			s.t.pe.adancime_maxima = aux;
 			printf("Viteza maxima de inot: ");
			scanf("%d", &aux);
 			s.t.pe.viteza_maxima = aux;
 			break;


		case 4:  //Pasare
			printf("Anvergura maxima: "); 
			scanf("%d", &aux);
			s.t.pa.anvergura = aux;
			printf("Altitudinea maxima de zbor: "); 
			scanf("%d", &aux);
			s.t.pa.altitudine_max = aux;
			printf("Viteza maxima de zbor: "); 
			scanf("%d", &aux);
			s.t.pa.viteza_maxima = aux;
			break;


		default:printf("Nu exista!");
			break;
 		}

		printf("\n\n");

 		switch (s.tip) {
 			case 1: //Mamifer
 				printf("Tip : Mamifer\n");
 				printf("Durata medie de viata: %d\n", s.durata_viata_medie);
 				printf("Perioada de gestatie: %d\n", s.t.m.perioada_gestatie);
				printf("Numarul mediu de pui pe care il naste: %d\n", s.t.m.numar_mediu_pui);
				printf("\n\n");
				break;


			case 2: //Insecta
				printf("Tip : Insecta\n");
				printf("Durata medie de viata: %d\n", s.durata_viata_medie);
				printf("Numarul de picioare: %d\n", s.t.i.numar_picioare);

				//daca zboara sau nu
				if (s.t.i.zboara)
					printf("Zboara\n");
				else 
					printf("Nu zboara\n");

				//daca e periculoasa sau nu
				if (s.t.i.periculoasa)
					printf("Este periculoasa pentru om! \n");
				else 
					printf("Nu este periculoasa pentru om!\n");

				printf("\n\n");
				break;


			case 3: //Peste
				printf("Tip : Peste\n");
				printf("Durata medie de viata: %d\n", s.durata_viata_medie);

				if (s.t.pe.tip)
					printf("Tipul de apa: dulce\n");
				else 
					printf("Tipul de apa: sarata\n");

				printf("Altitudinea maxima la care se poate gasi : %d\n", s.t.pe.adancime_maxima);
				printf("Viteza maxima de inot : %d\n", s.t.pe.viteza_maxima);
				printf("\n\n");
				break;


			case 4:  //Pasare
				printf("Tip : Pasare\n");
				printf("Durata medie de viata: %d\n", s.durata_viata_medie);
				printf("Anvergura aripilor: %d\n", s.t.pa.anvergura);
				printf("Altitudinea maxima de zbor: %d\n", s.t.pa.altitudine_max);
				printf("Viteza maxima de zbor: %d\n", s.t.pa.viteza_maxima);
				printf("\n\n");
				break;

			default: 
			break;
		}
	}
	else 
	printf("Nu exista tipul ales! \n");
	
	system("pause");
	return 0;
}


