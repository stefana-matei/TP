/*1.7. Se consideră două numere naturale nr1 şi nr2, ambele cuprinse între 0 şi 255. Se cere să se memoreze cele două numere într-un întreg nr reprezentabil pe 16 biţi fără semn (deci de tip unsigned short).
Indicatie: Cele două numere nr1 şi nr2 pot fi reprezentate pe 8 biţi. De aceea cei 16 biţi ai lui nr sunt suficienţi. Stocăm nr1 pe primii 8 biţi ai lui nr, iar pe nr2 pe ultimii 8 biţi ai lui nr.
nr = nr1 * 256 + nr2 ;
De asemenea, dacă se cunoaşte nr, se pot obţine valorile lui nr1 şi nr2 astfel:
nr1 = nr >> 8 ; // sau nr1 = nr / 256
nr2= nr & 255 ; // sau nr2 = nr % 256 ;*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	unsigned short nr1, nr2, nr;

	printf("nr1 = ");
	scanf("%hu", &nr1);

	printf("nr2 = ");
	scanf("%hu", &nr2);

	nr = nr1 * 256 + nr2;

	printf("\nnr = %hu\n", nr); //decimal
	for (int poz = 15; poz >= 0; poz--)
	{
		if (poz == 7)
			printf(" ");
		
		printf("%d", (nr >> poz) & 1); //bit
	}


	printf("\n\n");

	system("pause");
	return 0;

}


