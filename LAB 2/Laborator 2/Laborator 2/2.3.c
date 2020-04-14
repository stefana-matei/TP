/*Se citesc de la tastatura m si n,fiecare mai mici decat 10.Sa se creeze o matrice in care la fiecare pozitie sa fie maximul indecsilor
acelei pozitii si sa se afiseze matricea.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void citire_matrice(int v[][10], int m, int n)
{
	int i, j;
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			printf("v[%d][%d] = ", i, j);
			scanf("%d", &v[i][j]);		
			if (i >= j) 
				v[i][j] = i;
			
			if (j >= i)
				v[i][j] = j;
		}
	}
}


void afisare_matrice(int v[][10], int m, int n) {
	int i, j;
	for (i = 0;i < m;i++) {
		printf("\n");
		for (j = 0;j < n;j++) {
			printf("%d\t", v[i][j]);
		}
	}
}

int main() {
	float a[10][10];
	int m, n;
	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	printf("\n");
	citire_matrice(a, m, n);
	printf("\n");
	afisare_matrice(a, m, n);
	printf("\n");
	system("pause");
	return 0;
}