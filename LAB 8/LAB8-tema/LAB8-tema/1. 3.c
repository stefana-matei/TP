/*1. 3. Se citeşte valoarea unui număr natural nr. Să se determine câtul şi restul împărţirii lui nr la 8.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int nr;
	printf("dati nr :  ");
	scanf("%d", &nr);
	printf("Catul este: %d\n", (nr >> 3));
	printf("Restul este: %d\n\n", (nr & 7));

	system("pause");
	return 0;
}