#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void citire_vector(int a[], int n)
{
	int i;
	for (i = 0;i < n;i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}

}

void afisare_vector(int a[], int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("a[%d] = %d\n", i,a[i]);
	
}

void sortare_crescatoare(int a[], int n)
{
	int i, aux = 0, stop;
	
	do {
		stop = 1;
		for (i = 1;i <= n;i++) {
			if (a[i] % 2 != 0) {
				if (a[i - 1] > a[i]) {
					aux = a[i];
					a[i] = a[i - 1];
					a[i - 1] = aux;
					stop = 0;
				}
			}
		}

	} while (!stop);
	
}


int main() {
	int n, v[20];
	printf("n = ");
	scanf("%d", &n);
	citire_vector(v, n);
	printf("\n\n");
	afisare_vector(v, n);
	sortare_crescatoare(v, n);
	printf("\nNunerele sortare crescator : \n");
	afisare_vector(v, n);
	system("pause");
	return 0;
	

}