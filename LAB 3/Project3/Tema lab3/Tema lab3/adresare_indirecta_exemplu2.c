#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() 
{

	int x = 10, y = 7;
	int*p = &x; //p va contine adresa lui x
	printf("%d\n", *p); //afiseaza valoarea pointata de p la x,adica 10

	p = &y; //p va contine adresa lui y
	*p = *p - 2; //va modifica valoarea de la adresa lui y(la care pointeaza p)
	printf("%d\n", y); //va afisa 5 deoarece valoarea lui y a fost modificata anterior prin intermediul lui p

	y = 1;
	printf("%d\n", *p); //va afisa 1 deoarece la adresa pointata de p se afla valoarea 1
	printf("%p\n", p); //va afisa adresa de memorie la care se afla y
	scanf("%d", p); //citeste o valoare si o depune la adresa continuta in p(noua valoare a lui y)
	
	system("pause");
	return 0;
}