#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define M 20 
#define N 10


void initializare(int* a[][N], int* m,int*n)
{
	int i, j, s = 1;
	for (i = 1;i <= *m;i++) {
		for (j = 1;j <= *n;j++, s++) {
			a[i][j] = s;
		}
	}
}

void afisare(int*a[][N], int* m, int*n)
{
	int i, j;
	for (i = 1;i <= *m;i++) {
		printf("\n");
		for (j = 1;j <= *n;j++) {
			printf("%3d\t", a[i][j]);
		}
	}

}


int main() {
	int x[M][N], m, n;
	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);

	initializare(&x, &m, &n);
	printf("\n");

	afisare(&x, &m, &n);
	printf("\n\n");

	system("pause");
	return 0;
}