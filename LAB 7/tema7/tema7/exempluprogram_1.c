/*	Următorul program declară o variabilă întreagă şi un tablou 
de 5 întregi şi afişează adresele de memorie la care sunt plasate în memorie.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main()
{
	int n, v[5];
	printf("variab n are dimens %d\n", sizeof(n));
	printf("variab n este plasata la adresa %p\n", &n);
	printf("variab v are dimens %d\n", sizeof(v));
	printf("variab v este plasata la adresa %p\n", v);

	system("pause");
	return 0;
}
