/*Program care citeste valori pana intalneste 0(exclusiv),dupa care afiseaza aceste valori in ordine inversa,
implementat cu indecsi.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int v[10];
	int i, j, n = 0, tmp; // n indica numarul de elemente din vector

	for (;;) {            // bucla infinita pentru citire
		printf("v[%d] = ", n);
		scanf("%d", &v[n]);
		if (v[n] == 0)
			break;
		n++; // considera valorea citita ca fiind introdusa
	}

	for (i = 0, j = n - 1;i < j;i++, j--) { //inversare valori
		tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}

	printf("\n\n");

	for (i = 0;i < n;i++) {
		printf("%d\n", v[i]);
	}

	system("pause");
	return 0;
}