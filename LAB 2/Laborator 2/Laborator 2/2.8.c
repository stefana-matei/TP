#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 15

void initializare_matrice(int a[][MAX], int n)
{
	int i, j, s = 0;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++, s++) {
			a[i][j] = s * s;
		}
	}
}

void afisare(int a[][MAX], int n)
{
	int i, j;
	for (i = 0;i < n;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf("%3d\t", a[i][j]);
		}
	}

}

int main() {
	int a[MAX][MAX], n;
	printf("n = ");
	scanf("%d", &n);

	initializare_matrice(a, n);
	printf("\n");

	afisare(a, n);
	printf("\n\n");

	system("pause");
	return 0;

}