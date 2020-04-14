/*Aplicația 3.4: Să se afișeze câte elemente negative sunt în vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși. 
(Fără indecși înseamnă că în cod nu va exista niciun v[i])*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int v[] = {7,-5,4,3,-9,2,-8};
	int*ptr,negativ = 0, n;

	ptr = v;	// ptr pointeaza la prima pozitie libera din vector ,deci ptr va fi egal cu primul element,adica 7!
	n = sizeof(v) / sizeof(ptr); //numarul de elemente exact din vector


	while (ptr < v + n) 
	{
		//afisare vector dat
		printf("%d\n\n", *ptr);

		//numarare elem. negative
		if ((*ptr) < 0) {
			negativ++; //nr de elemente negative
		}
		ptr++;

	}

	printf("Numarul de elemente negative din vector este %d\n\n", negativ);


	system("pause");
	return 0;
}
