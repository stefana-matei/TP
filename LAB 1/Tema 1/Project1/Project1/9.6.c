#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


unsigned int cmmdc(unsigned int a, unsigned int b)//calcul cel mai mare divizor comun
{
	if (a == b)
		return a;
	else
		if (a > b)
			return cmmdc(a - b, b);
		else
			return cmmdc(a, b - a);
}

int main()
{
	unsigned int a, b;
	printf("a = ");
	scanf("%u", &a);
	printf("b = ");
	scanf("%u", &b);

	if (!a || !b)
		printf("(%u,%u) = 1\n", a, b);
	else
		printf("cmmdc(%u,%u) = %u\n", a, b, cmmdc(a, b));

	system("pause");
	return 0;
}