#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void linieOrizontala(int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("*");
	printf("\n");
}


void linieVerticala(int n)
{
	int i, j;
	for (i = 0;i < (n - 2) / 2;i++) {
		for (j = 0;j < n;j++) {
			if (j == 0 || j == n - 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}

int validare_n(int n)
{
	if (n <= 4) {
		printf("Nu poate fi n mai mic sau egal decat 4!\n\n");
		exit(0);
	}
	else if (n % 2 == 0) {
		printf("Nu poate fi numar par!\n\n");
		exit(0);
	}

}


int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	validare_n(n);
	linieOrizontala(n);
	linieVerticala(n);
	linieOrizontala(n);
	linieVerticala(n);
	linieOrizontala(n);

	system("pause");
	return 0;
}