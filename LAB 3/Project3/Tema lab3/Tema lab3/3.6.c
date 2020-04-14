/* Aplicația 3.6: Se citește un număr n (n<=10) și apoi n numere întregi. 
Se cere să se sorteze aceste numere în ordine descrescătoare utilizând pointeri, fără indecși. (Inclusiv citirea se va face cu pointeri.)*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main()
{
	int v[10];
	int*ptr, n;
	int aux, k;

	ptr = v;

	printf("n = ");
	scanf("%d", &n);

	printf("\n");

	//citire
	for (ptr = v;ptr < v+n;ptr++) {  
		printf("v[%d] = ", ptr - v); //ptr-v index 
		scanf("%d", ptr);
	}


	printf("\nNumerele citite sunt : \t");
	for (ptr = v;ptr < v + n;ptr++) {  //afisare
		printf(" %d ", *ptr);
	}

	printf("\n\n");

	
	// sortare descrescatoare
	do
	{
		k = 1;
		for (ptr=v+1; ptr < v + n; ptr++)	// ptr=v+1 ADICA v[1] 
			if (*(ptr - 1) < *ptr) {	// *(ptr-1) ADICA v[0]
				aux = *ptr;
				*ptr = *(ptr - 1);
				*(ptr - 1) = aux;
				k = 0;
			}
	} while (!k);

	printf("Numerele sortate descrescator :\t");
	for (ptr = v;ptr < v + n;ptr++) {  //afisare
		printf(" %d ", *ptr);
	}

	printf("\n\n");





	system("pause");
	return 0;
}
