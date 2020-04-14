#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void citire_matrice(float mat[][10], int m, int n)
{
	int i, j;
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			printf("mat[%d][%d] = ", i, j);
			scanf("%f", &mat[i][j]);
		}
	}
}


void citire_vector(float v[], int k)
{
	int i;
	for (i = 0;i < k;i++) {
		printf("v[%d] = ", i);
		scanf("%f", &v[i]);
	}
}

void egal(float mat[][10], float v[], int m, int n, int k)
{
	int i, j, t, egale;

	for (t = 0;t < k;t++) {

		egale = 0;

		for (i = 0;i < m;i++) {

			for (j = 0;j < n;j++) {
				if (v[t] == mat[i][j]) {
					printf("(%d,%d)\n", i, j);
					egale = 1;
					break;
				}
			}

			if (egale) 
				break;
		}

		if (!egale) {
			printf("Numarul nu a fost gasit!\n");
		}

	}

}



int main() {
	int m, n, k;
	float a[10][10], v[10];

	printf(" m = ");
	scanf("%d", &m);
	printf(" n = ");
	scanf("%d", &n);
	printf("\n");

	citire_matrice(a, m, n);
	printf("\n\n");

	printf(" k = ");
	scanf("%d", &k);

	citire_vector(v, k);
	printf("\n\n");

	egal(a, v, m, n, k);
	printf("\n");
	system("pause");
	return 0;


}