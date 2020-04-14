#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


 int indice_minim_maxim_vector(int v[],int n)
{
	 int i, min, max, ind[2], indice_min, indice_max;

	for (i = 0;i < n;i++) {
		printf("v[%d] = ", i);
		scanf("%d", &v[i]);
	}

	min = v[0];
	max = v[n-1];
	for (i = 0;i < n;i++) {
		if (min >= v[i]) {
			min = v[i];
			indice_min = i;
		}

		if (max <= v[i]) {
			max = v[i];
			indice_max = i;
		}

	}

	ind[0] = indice_min;
	ind[1] = indice_max;
	
	printf("Minimul %d cu indicele %d\n Maximul %d cu indicele %d\n", min, ind[0], max, ind[1]);

	return ind;

}

int main() {
	int v[20], n;

	printf("Numarul de elemente al vectorului : ");
	scanf("%d", &n);
	
	printf("\n\n");
	
	indice_minim_maxim_vector(v, n);
	
	printf("\n");
	system("pause");
	return 0;

}