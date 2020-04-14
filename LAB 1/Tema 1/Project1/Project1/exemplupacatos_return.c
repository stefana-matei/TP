#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int verificare(float v[MAX], int n)
{
	int i, verif;

	for (i = 0;i < n;i++) {
		printf("v[%d] = ", i);
		scanf("%f", &v[i]);
	}

	for (i = 0;i < n;i++) {
		if (v[i] < 0)
			return 0;
	}
	return 1;
}

int main() {
	float v[MAX];
	int n;
	printf("n = ");
	scanf("%d", &n);

	printf("%d\n", verificare(v, n));
	system("pause");
	return 0;

}