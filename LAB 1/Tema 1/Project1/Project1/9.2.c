#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define citire(v) scanf("%f",&v);

int valoarea_maxima(float a, float b, float c)
{
	int max;
	if (a >= b && a >= c)
		max = a;
	else if (b >= c && b >= a)
		max = b;
	else
		max = c;

	return max;

}

int main()
{
	float x, y, z;
	printf(" x = ");
	citire(x);
	printf(" y = ");
	citire(y);
	printf(" z = ");
	citire(z);
	printf("\nMaximul dintre cele trei valori este : \t");
	printf("%d\n", valoarea_maxima(x, y, z));
	system("pause");
	return 0;
}