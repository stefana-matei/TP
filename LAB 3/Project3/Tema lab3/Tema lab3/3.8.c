/*Aplicația 3.8: Se dă vectorul {7, -5, 4, 3, -9, 2, -8}. 
Să se insereze înainte de fiecare valoare din vectorul original negativul ei. Utilizați pointeri, fără indecși.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int v[15] = { 7,-5,4,3,-9,2,-8 }, n = 7;
	int*ptr, *p, count=0;

	ptr = v; // ptr pointeaza la prima pozitie libera din vector


	for (ptr=v;ptr < v+n;ptr += 2) {
		for (p = v+n;p > ptr;p--) { // j=n;j>i;j--

			*p = *(p -1); //spre stanga deplasarea
		}

		n++;
		*ptr = -*ptr; //va afisa opusul fiecarui numar
	}


	for (ptr = v;ptr < v + n;ptr++) { //afisare a numerelor cu opusul lor

		count++;

		if (*ptr >= 0) {
			printf("\t %d\t", *ptr);
		}
		else {
			printf("\t%d\t", *ptr);
		}

		if (count % 2 == 0) {
			printf("\n");
		}

	}

	system("pause");
	return 0;

}
