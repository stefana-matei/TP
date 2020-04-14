#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int v[] = {5,8,1,4,2,6,9}, n;
	int*ptr,*p;
	ptr = v;
	p = v;

	n = sizeof(v) / sizeof(ptr);

	for (ptr = v;ptr < v+n;ptr++)
	{
		if ((*ptr) % 2 == 0)
		{
			for (p = ptr;p < (v+n)-1;p++)
			{
				*p = *(p+ 1);
			}
			ptr--;
			n--;
		}
	}

	for (ptr = v;ptr < v + n;ptr++) {  //afisarea vectorului fara numnerele pare
		printf("%d\n\n", *ptr);
	}



	system("pause");
	return 0;
}
