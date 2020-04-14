/*Să se implementeze, fără a se folosi variabile index, un program cu următorul meniu:
1. Citire -citește o valoare reală și o adaugă într-un vector cu maxim 100 de elemente
2.Afișare -afișează toate valorile din vector
3.Ștergere -citește o valoare și șterge toate elementele egale cu valoarea citită
4. Ieșire
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
	float v[101], x, valoare;
	float *ptr,*p;
	int optiune, k = -1;
	ptr = v;

	do {
		printf("1.Citire\n");
		printf("2.Afisare valori\n");
		printf("3.Stergere elemente egale cu o valoare citita\n");
		printf("4.Iesire\n");
		printf("Optiunea dvs. este : ");
		scanf("%d",&optiune);
		printf("\n");
		switch (optiune)
		{
		case 1: //citire
			printf("Se citeste o valoare reala : ");
			scanf("%f", &x);
			k++;
			*(v + k) = x;
			printf("\n");
			break;
		case 2: //afisare
			printf("\n");
			printf("Valorile vectorului : ");
			for (ptr = v;ptr <= v + k;ptr++) {  
				printf(" %.3f ", *ptr);
			}
			printf("\n\n");
			break;
		case 3: //stergere
			printf("Valoare ce trebuie sa fie stearsa : ");
			scanf("%f", &valoare);

			for (ptr = v;ptr <= v + k;ptr++)
			{
				if (*ptr == valoare) {
					for (p = ptr;p <= (v + k) - 1;p++)
					{
						*p = *(p + 1);
					}
					ptr--;
					k--;
				}
			}
			break;
		case 4:exit(0);
			break;
		default:printf("Optiunea aleasa nu exista!\n");
			break;
		}

	} while (optiune != 4);

	system("pause");
	return 0;
}