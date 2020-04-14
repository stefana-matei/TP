#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float v[101], x;
	int opt, k = -1, i, j;
	int *po;
	float *px;
	po = &opt;
	px = &x;
	do
	{
		printf("\n1.Adaugare valoare in vector\n");
		printf("2.Afisare valori\n");
		printf("3.Stergere elemente egale cu o valoare citita\n");
		printf("4.Iesire\n");
		printf("Optiunea dvs. este: ");
		scanf("%d", po);
		switch (opt)
		{
		case 1:
			printf("x=");
			scanf("%f", px);
			k++;
			*(v + k) = x;
			break;
		case 2:
			printf("v=");
			for (i = 0; i <= k; i++)
				printf("%f ", *(v + i));
			break;
		case 3:
			printf("val=");
			scanf("%f", px);
			for (i = 0; i <= k; i++)
			{
				if (*(v + i) == x)
				{
					for (j = i; j < k; j++)
						*(v + j) = *(v + j + 1);
					i--;
					k--;
				}

			}
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Optiune gresita!\n");
			break;
		}
	} while (1);
	return 0;
}
