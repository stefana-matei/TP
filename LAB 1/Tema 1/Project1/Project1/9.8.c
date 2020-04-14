#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


unsigned int A(unsigned int m, unsigned int n)
{
	if (m == 0)
		return n + 1;
	else if (m > 0 && n == 0)
		return A(m - 1, 1);
	else if(m>0 && n>0)
		return A(m - 1, A(m, n - 1));
}

int main() {
	unsigned int m, n;
	printf("m = ");
	scanf("%u", &m);
	printf("n = ");
	scanf("%u", &n);
	printf("A(%u,%u) = %u\n", m, n, A(m, n));
	system("pause");
	return 0;
}
