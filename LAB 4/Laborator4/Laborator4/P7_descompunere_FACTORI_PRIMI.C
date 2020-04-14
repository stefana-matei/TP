/*Sa se descompuna un numar in factori primi memorand rezultatul sub forma unui vector de structuri.
Fiecare element va cuprinde doua campuri: 
a. unul care contine divizorul prim 
b. unul care contine puterea la care apare acesta in descompunere 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct {
	int valoare, putere;
}
factori;

int verificare_prim(int nr) {
	int i;
	for (i = 2; i < nr / 2 + 1; i++) {
		if (nr % i == 0) {
			return 0;   //numarul nu este prim
		}
	}

	return 1;    //numar prim
}

int descompunere(factori * set, int nr, int * count) 
{
	int i;
	for (i = 2; i < abs(nr) / 2 + 1; i++) {
		if (nr % i == 0) {
			if (verificare_prim(i)) //verificare prim astfel incat sa se afiseze doar factorii primi
				set[(*count)++].valoare = i;
			
		}
	}
	return (*count);
}

void afisare_factor(factori * set, int counter) {
	printf("\n%d", set[counter].valoare);
}

int main() {

	int numar, n = 0, i;

	factori factor[10];

	printf("Scrieti numarul : ");
	scanf("%d", &numar);

	if (descompunere(factor, numar, &n)) {
		printf("\nDivizorii numarului: \n");

		for (i = 0; i < n; i++) {
			afisare_factor(factor, i);
		}
	}
	else {
		printf("\n%d este numar prim!\n", numar);
	}

	printf("\n");
	system("pause");
	return 0;

}