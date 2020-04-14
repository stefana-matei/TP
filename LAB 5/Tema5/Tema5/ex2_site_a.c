/*2) Se va scrie un program C ce va evidenţia diferenţele între folosirea unei structuri şi a unei uniuni 
a) se va folosi o structură de înregistrări
b) se va folosi o structură tip uniune*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>



//a) se va folosi o structură de înregistrări
 struct exemplu
{
	long int a;
	char* b;
	char* c;
};


int main()
{
	struct exemplu x;
	printf("Spatiul ocupat de o variabila la structura: %d\n", sizeof(x));
	x.a = 45;
	x.b = "Ana are mere colorate";
	x.c = "Andrei invata bine la scoala";

	printf("%ld\n", x.a);
	printf("%s\n", x.b);
	printf("%s\n", x.c);

	system("pause");
	return 0;
}
