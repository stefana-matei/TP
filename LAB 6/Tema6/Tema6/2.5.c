/*Aplicația 2.5: Se consideră că o măsurătoare are asociată unitatea de măsură (gram, metru, litru) și
multiplicatorul acesteia 
(pico, nano, mili, centi, deci, deca, hecto, kilo, mega, giga). 
•	Să se codifice o măsurătoare astfel încât să conțină o valoare întreagă pozitivă care să acopere un interval 
cât mai mare de valori, unitatea de măsură și multiplicatorul acesteia. O măsurătoare va ocupa exact 2 octeți.
•	Să se citească o valoare unsigned și o unitate de măsură. La citire nu există multiplicator. 
Să se determine multiplicatorul astfel încât valoarea stocată să fie cât mai mică, fără a se pierde precizie,
iar apoi să se stocheze într-o măsurătoare. Dacă valoarea nu încape, se va afișa o eroare. Să se afișeze toate câmpurile măsurătorii.
	valoare=147000, unitate:gram     =>     147 kilogram

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef enum { gram, metru, litru } Unitate_masura;

typedef enum { pico, nano, mili, centi, deci, deca, hecto, kilo, mega, giga } Multiplicator;
const char *multiplicator_gram[] = { "picograme","nanograme","miligrame","centigrame", "decigrame","decagrame", "hectograme", "kilograme", "megagrame", "gigagrame" };
const char *multiplicator_metru[] = { "picometri","nanometri","milimetri","centimetri", "decimetri","decametri", "hectometri", "kilometri", "megametri", "gigametri" };
const char *multiplicator_litru[] = { "picolitri","nanolitri","mililitri","centilitri", "decilitri","decalitri", "hectolitri", "kilolitri", "megalitri", "gigalitri" };


typedef struct 
{
	unsigned int nr;
	Unitate_masura um;
	Multiplicator multipli;

}Masuratoare;


void citire( Masuratoare *m)
{
	int unitate_masura;

	printf("Scrieti o valoare : ");
	scanf("%u", &m->nr);

	printf("Unitatea de masura (0-gram,1-metru,2-litru) : ");
	scanf("%d", &unitate_masura);
	m->um = unitate_masura;
}


void afisare(Masuratoare *m)
{
	
	if (m->um == 0) {   //daca unitatea de masura este gram

		unsigned int multiplicat,unitate_m;
		printf("%u grame", m->nr);
		multiplicat = m->nr;

		if (multiplicat >= 10 && multiplicat < 100)  //decagram
		{
			multiplicat = multiplicat / 10;
			unitate_m = (unsigned int)deca;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_gram[m->multipli]);
		}
		else if (multiplicat >= 100 && multiplicat < pow(10, 3)){  //hectogram

			multiplicat = multiplicat / 100;
			unitate_m = (unsigned int)hecto;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_gram[m->multipli]);
		}
		else if (multiplicat >= pow(10, 3) && multiplicat < pow(10, 6)) { //kilogram

			multiplicat = multiplicat / pow(10, 3);
			unitate_m = (unsigned int)kilo;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_gram[m->multipli]);
		}
		else if (multiplicat >= pow(10, 6) && multiplicat < pow(10, 9)) { //megagram

			multiplicat = multiplicat / pow(10, 6);
			unitate_m = (unsigned int)mega;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_gram[m->multipli]);
		}
		else if (multiplicat >= pow(10, 9) && multiplicat < pow(10, 12)) { //gigagram

			multiplicat = multiplicat / pow(10, 9);
			unitate_m = (unsigned int)giga;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_gram[m->multipli]);
		}
		else
			printf(" => Eroare!\n");

	}
	else if (m->um == 1) { 	//daca unitatea de masura este metru

		unsigned int multiplicat, unitate_m;
		printf("%u metri", m->nr);
		multiplicat = m->nr;

		if (multiplicat >= 10 && multiplicat < 100) {  //decametri

			multiplicat = multiplicat / 10;
			unitate_m = (unsigned int)deca;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_metru[m->multipli]);
		}
		else if (multiplicat >= 100 && multiplicat < pow(10, 3)) {  //hectometri

			multiplicat = multiplicat / 100;
			unitate_m = (unsigned int)hecto;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_metru[m->multipli]);
		}
		else if (multiplicat >= pow(10, 3) && multiplicat < pow(10, 6)) {  //kilometri

			multiplicat = multiplicat / pow(10, 3);
			unitate_m = (unsigned int)kilo;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_metru[m->multipli]);
		}
		else if (multiplicat >= pow(10, 6) && multiplicat < pow(10, 9)) {  //megametri

			multiplicat = multiplicat / pow(10, 6);
			unitate_m = (unsigned int)mega;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_metru[m->multipli]);
		}
		else if (multiplicat >= pow(10, 9) && multiplicat < pow(10, 10)) {  //gigametri

			multiplicat = multiplicat / pow(10, 9);
			unitate_m = (unsigned int)giga;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_metru[m->multipli]);
		}
		else
			printf(" => Eroare!\n");
	}
	else {  //daca unitatea de masura este litru

		unsigned int multiplicat, unitate_m;
		printf("%u litri", m->nr);
		multiplicat = m->nr;

		if (multiplicat >= 10 && multiplicat < 100) {  //decalitri

			multiplicat = multiplicat / 10;
			unitate_m = (unsigned int)deca;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_litru[m->multipli]);
		}
		else if (multiplicat >= 100 && multiplicat < pow(10, 3)) {  //hectolitri

			multiplicat = multiplicat / 100;
			unitate_m = (unsigned int)hecto;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_litru[m->multipli]);
		}
		else if (multiplicat >= pow(10, 3) && multiplicat < pow(10, 6)) {  //kilolitri

			multiplicat = multiplicat / pow(10, 3);
			unitate_m = (unsigned int)kilo;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_litru[m->multipli]);
		}
		else if (multiplicat >= pow(10, 6) && multiplicat < pow(10, 9)) {  //megalitri

			multiplicat = multiplicat / pow(10, 6);
			unitate_m = (unsigned int)mega;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_litru[m->multipli]);
		}
		else if (multiplicat >= pow(10, 9) && multiplicat < pow(10, 10)) {  //gigalitri

			multiplicat = multiplicat / pow(10, 9);
			unitate_m = (unsigned int)giga;
			m->multipli = unitate_m;
			printf(" => %u %s\n", multiplicat, multiplicator_litru[m->multipli]);
		}
		else
			printf("=>Eroare!\n");
	}
}


int main()
{
	Masuratoare m;
	citire(&m);
	printf("\n");
	afisare(&m);
	printf("\n");

	system("pause");
	return 0;
}