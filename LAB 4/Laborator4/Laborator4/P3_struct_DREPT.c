/*Se defineste o structura „Drept” care contine latimea l si inaltimea h a dreptunghiului. Se cere nr<=5 si apoi cele nr dreptunghiuri. 
Sa se afiseze informatii despre componentele dreptunghiului de arie maxima. Folositi definitia de tip typedef
typedef struct{ 
int l,h; 
}Drept; 
…. 
Drept d[5]; 
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int l, h;
}Drept;

int main()
{
	Drept d[5];
	int i, nr, aria, max = 0;

	printf("Numarul de dreptunghiuri : ");
	scanf("%d", &nr);
	printf("\n");

	for (i = 0;i < nr;i++) {
		printf("l[%d] = ", i + 1);
		scanf("%d", &d[i].l);

		printf("\n");

		printf("h[%d] = ", i + 1);
		scanf("%d", &d[i].h);

		printf("\n");

		aria = (d[i].l * d[i].h);

		if (max < aria)
			max = aria;
	}

	for (i = 0;i < nr;i++) {
		aria = (d[i].l * d[i].h);

		if (max == aria)
			printf("Aria maxima este %d formata din laturile %d si %d\n\n ", max, d[i].l, d[i].h);
	}

	system("pause");
	return 0;
}