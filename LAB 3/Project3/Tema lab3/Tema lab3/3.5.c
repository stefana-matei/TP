/*Aplicația 3.5: Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int v[] = { 7,-5,4,3,-9,2,-8};
	int*ptr,*min, n;

	ptr = v;
	min = v;
	

	n = sizeof(v) / sizeof(ptr);

	while (ptr < v + n) 
	{
		printf("%d\n\n", *ptr);

		if (*ptr < *min) 
			*min = *ptr;

		ptr++;

	}

	printf("Minimul este %d\n", *min);

	system("pause");
	return 0;
}
