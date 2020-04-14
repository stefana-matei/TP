/*Aplicația 3.2: Se citesc două variabile, a și b, de tip întreg.
Să se stocheze într-un pointer adresa variabilei care conține valoarea maximă și apoi să se afișeze valoarea pointată.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int valoare_maxima(int*x, int*y)
{
	if (*x > *y)
		return *x;
	else
		return *y;
}

int main() 
{
	int a, b;
	printf("a = ");
	scanf("%d", &a);

	printf("b = ");
	scanf("%d", &b);

	printf("\nValoarea maxima este %d!\n", valoare_maxima(&a, &b));  //functiei i se paseaza adresele  lui a si b
	system("pause");
	return 0;

}