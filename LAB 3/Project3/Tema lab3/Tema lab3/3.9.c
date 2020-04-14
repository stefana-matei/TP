/* Aplicația 3.9: Se citesc n<=10 valori întregi.
Folosind doar pointeri, fără niciun fel de indexare, să se afișeze toate valorile care au cel puțin un duplicat. (Inclusiv citirea se va face cu pointeri.)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int v[20];
	int*ptr, *p,*t;
	int ok, n;
	ptr = v;

	printf("n = ");
	scanf("%d", &n);
	printf("\n");

	for (ptr = v;ptr < v + n;ptr++) {  //citire
		printf("v[%d] = ", ptr - v);
		scanf("%d", ptr);
	}

	printf("\n\n");

	printf("Valorile ce sunt duplicate sunt : \n");
	for (ptr=v;ptr < v+n ;ptr++)
	{
		ok = 0;
		for (p = ptr + 1;p < v+n;p++)
		{
			if (*ptr == *(p))
			{
				ok = 1;
				for (t = p;t < v+n;t++)
				{
					*(t) = *(t + 1);
				}
				p--;
				n--;
			}
		}

		if (ok == 1) 
			printf("%d\t", *ptr);
	
	}

	printf("\n");
	system("pause");
	return 0;
}

