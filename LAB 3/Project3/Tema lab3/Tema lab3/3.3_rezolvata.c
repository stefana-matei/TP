/*Scrieti un program care interschimba valorile a doua variabile de tip intreg utilizand pointeri.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* aceasta functie nu interschimba a si b ,deoarece in interiorul ei se actioneaza asupra unor copii
 si doar acestea se modifica*/
void incercare(int a, int b)
{
	int aux = a;
	a = b;
	b = aux;
}

/*aceasta functie reuseste sa interschimbe doua valori fiindca ea primeste ca parametri adresele acestor
valori,deci operatiile din interiorul ei se vor realiza chiar pe originale*/
void interschimba(int*pa, int*pb)
{
	int aux = *pa;
	*pa = *pb;
	*pb = aux;
}

int main() 
{
	int x = 10, y = 7;
	incercare(x, y);
	printf("%d %d\n", x, y); // 10 7 deoarece valorile nu au fost interschimbate

	printf("\n\n");

	interschimba(&x, &y); //functiei i se paseaza adresele  lui x si y
	printf("%d %d\n", x, y); // 7 10 deoarece valorile au fost interschimbate prin intermediul adreselor lor

	system("pause");
	return 0;


}