#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define citire(v) scanf("%d",&v);

int sortare_crescator(int*a, int*b)
{
	int aux = 0;
	if (*b < *a) {
		aux = *b;
		*b = *a;
		*a = aux;
	}
	return *a, *b;
}

int main() {
	int x, y;
	printf(" x = ");
	citire(x);
	printf(" y = ");
	citire(y);

	sortare_crescator(&x, &y);
	printf("\n");

	printf("Numerele sortate crescator : %d , %d\n", x, y);
	system("pause");
	return 0;
}