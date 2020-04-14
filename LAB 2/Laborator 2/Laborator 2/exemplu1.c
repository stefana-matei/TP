#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void citire_matrice(int v[][12], int m, int n)
{
	int i, j;
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			printf("v[%d][%d] = ", i, j);
			scanf("%d", &v[i][j]);
		}
	}

}


int algoritm_testare(int v[][12], int m, int n)
{
	int i, j, toate = 1;
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			if (v[i][j] < 0) {
				toate = 0;
				break;
			}
		}
	}

	if (toate) {
		printf("Matricea are toate elementele pozitive.\n");
	}
	else {
		printf("Matricea are si elemente negative!\n");
	}
	return 0;
}


int main() {
	int a[10][12];
	int m, n;
	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	citire_matrice(a, m, n);
	algoritm_testare(a, m, n);
	system("pause");
	return 0;
}