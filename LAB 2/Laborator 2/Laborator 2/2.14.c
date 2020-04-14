#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10



void produs(int*p[][MAX], int n)
{
	int i, j;
	for (i = 0;i < n;i++) 
	{
		printf("\n");
		for (j = 0;j < 4;j++) 
		{
			printf("produs[%d][%d] = ", i, j);
			scanf("%d", &p[i][j]);	
		}
	}

}


void vanzari(int*p[][MAX], int n)
{
	int i,j, crestere;

	for (i = 0;i < n;i++) {
		crestere = 1;

		for (j = 0;j < 3;j++) {

			if (p[i][j] > p[i][j + 1]) {
				crestere = 0;
				break;
			}
		}

		if (crestere == 1) {
			printf("Produsul %d a inregistrat o crestere continua!\n", i);
		}
	}
}


int main() {
	int* p[MAX][MAX], n;

	printf("Numar de produse : ");
	scanf("%d", &n);
	printf("\n");

	produs(&p, n);
	printf("\n");

	vanzari(&p, n);
	printf("\n");

	system("pause");
	return 0;
}