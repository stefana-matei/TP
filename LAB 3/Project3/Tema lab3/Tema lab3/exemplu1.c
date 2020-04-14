#include <stdio.h>


int main() 
{
	int a = 7, b = 1;
	int*p = &a; //pointerul p este initializat cu adresa variabilei a
	int*r = p; //pointerul r este initializat cu adresa stocata in pointerul p
	p = &b; //pointerul p i se atribuie adresa variabilei b 

	// ! in acest moment pointerul p va contine adresa variabilei b
	// ! iar pointerul r va contine adresa variabilei a

	printf("&a = %p\n &b = %p\n", r, p); //se afiseaza adresa continuta de un pointer prin %p in hexazecimal
	system("pause");
	return 0;
}