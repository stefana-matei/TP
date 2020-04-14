/*Se defineste o structura „Punct” cu membrii „a” si „b”numere  reale.
 Se cere o valoare  v<=10 si apoi v puncte. Sa se calculeze distanta dintre cele mai apropiate doua puncte si sa se afiseze. 
Se va folosi din  <math.h>  functia „sqrt” (square root), pentru extragerea radicalului. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float a, b;
}Punct;



int main()
{
	Punct pct[10];
	int v, i, j;
	float distanta = 0, d_max;

	printf("Numarul de puncte : ");
	scanf("%d", &v);
	printf("\n");

	for (i = 0;i < v;i++) {
		printf("x[%d] = ",i+1);
		scanf("%f", &pct[i].a);

		printf("\n");

		printf("y[%d] = ", i + 1);
		scanf("%f", &pct[i].b);

		printf("\n");

	}

	for (i = 0;i < v;i++)
	{
		for (j = i + 1;j < v;j++) {
			d_max = sqrt(pow(pct[i].a - pct[j].a, 2) + pow(pct[i].b - pct[j].b, 2));
			if (distanta < d_max)
				distanta = d_max;
		}
	}

	printf("Distanta dintre cele mai apropiate doua puncte %f si %f  este: %f\n\n", distanta);

	system("pause");
	return 0;
}