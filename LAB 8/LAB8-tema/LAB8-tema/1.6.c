/*1.6. Se citesc 2 valori naturale nr. şi bit (0 <= bit <= 15). Să se marcheze cu 1 bitul bit al lui nr.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nr;
	unsigned short bit;

	printf("dati nr : ");
	scanf("%d", &nr);

	for (int poz = 15; poz >= 0; poz--)
		printf("%d", ((nr >> poz) & 1));

	printf("\nal catelea bit? ");
	scanf("%hu", &bit);
	printf("%d\n\n", nr & (1 << bit));

	system("pause");
	return 0;
}

