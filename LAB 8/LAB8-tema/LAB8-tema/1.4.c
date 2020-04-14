/*1.4. Se citeşte valoarea unui număr natural nr. Să se scrie reprezentarea lui nr în baza 2.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int nr;
	printf("dati nr : ");
	scanf("%d", &nr);

	for (int poz = 15; poz >= 0; poz--) { //poz reprezinta pozitia fiecarui bit
		printf(" %d ", ((nr >> poz) & 1));
	}

	system("pause");
	return 0;
}