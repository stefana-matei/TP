#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void citire(int v[], int n)
{
	int i;
	for (i = 0;i < n;i++) {
		printf("v[%d] = ", i);
		scanf("%d", &v[i]);
	}

}

void egal(int v1[], int v2[], int n)
{
	int i;
	int egale = 1;

	for (i = 0;i < n;i++) {
		if (v1[i] != v2[i]) {
			egale = 0;
		}
	}

	if (egale)
		printf("Elementele din v1 sunt egale cu cele din v2!\n");
	else
		printf("Elementele din v1 NU sunt egale cu cele din v2!\n");


}


int main() {
	int n, v1[10], v2[10];

	printf(" n = ");
	scanf("%d", &n);

	if (n >= 10) {
		printf("\nNu indeplineste cerinta!\n\n");
		exit(0);
	}

	printf("Citire vector1 : \n");
	citire(v1, n);

	printf("\n\n");

	printf("Citire vector2 : \n");
	citire(v2, n);
	egal(v1, v2, n);

	system("pause");
	return 0;
}