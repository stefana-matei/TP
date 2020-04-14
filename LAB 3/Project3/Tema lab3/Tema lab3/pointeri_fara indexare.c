/*varianta cu pointeri,fara niciun index.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int v[10];
	int*end, *p, *r;
	int tmp;
	end = v; // end pointeaza la prima pozitie libera din vector

	for (;;) {            // bucla infinita pentru citire
		printf("v[%d] = ", end-v); // numar de elemente deja introduse in vector
		scanf("%d", end);
		if (*end == 0)
			break;
		end++; // trece la urmatoarea adresa
	}

	for (p = v, r = end - 1 ;p < r ; p++, r--) { //inversare valori
		tmp = *p;
		*p = *r;
		*r = tmp;
	}

	printf("\n\n");

	for (p=v;p < end;p++) {
		printf("%d\n",*p);
	}

	system("pause");
	return 0;
}