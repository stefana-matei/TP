#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int v[102], valoare, index = -1, k, aux = 0;
	int *px, *pv;
	px = &valoare;
	pv = v;

	while (*px != 0)
	{
		// adaugare
		printf("Adaugati o valoare : ");
		scanf("%d", px);
		index++;
		*(v + index) = valoare;
		
		// sortare
		do
		{
			k = 1;
			for (pv = v + 1; pv <= v + index; pv++)
				if (*(pv - 1) > *pv) {
					aux = *pv;
					*pv = *(pv - 1);
					*(pv - 1) = aux;
					k = 0;
				}
		} while (!k);


		// afisare
		printf("v = ");
		for (pv = v; pv <= v + index; pv++)
			printf("%d ", *(pv));
		printf("\n");
	}

	system("pause");
	return 0;
}
