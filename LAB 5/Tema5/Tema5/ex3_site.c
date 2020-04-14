/*3) Să se realizeze o aplicaţie care realizează prelucrări cu numere complexe,
adică citire, afişare, modul, sumă şi produs între două astfel de numere*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

typedef struct {
	float a;	//partea reala
	float b;	//partea imaginara
}complex;	



//citirea unui nr. complex
void citire(complex* z, char s[]) //s retine numele nr. complex
{
	printf("Introducem nr. complex %s :\n", s);
	printf("Partea reala: ");
	scanf("%f", &(*z).a);
	printf("Partea imaginara: ");
	scanf("%f", &z->b); //alt mod de scriere
}


//afisarea unui nr. complex
void afisare(complex z, char s[])
{
	printf("Nr. complex %s: ", s);
	if (z.b >= 0)
		printf("%.2f+%.2fi\n", z.a, z.b);
	else
		printf("%.2f%.2fi\n", z.a, z.b);
}

//modulul unui nr. complex
float modul(complex z)
{
	return sqrt(pow(z.a, 2) + pow(z.b, 2));
}


//conjugatul unui numar complex
complex conjugat(complex z)
{
	complex t;
	t.a = z.a;
	t.b = -z.b;
	return t;
}

//suma a doua nr. complexe (varianta cu transfer prin tipul rezultat)
complex suma1(complex x, complex y)
{
	complex z;
	z.a = x.a + y.a;
	z.b = x.b + y.b;
	return z;
}

//suma a doua nr. complexe (varianta cu transfer prin linia de parametri)
void suma2(complex x, complex y, complex* z)
{
	z->a = x.a + y.a; //(*z).a=x.a+y.a;
	z->b = x.b + y.b;
}

//produsul a doua nr. complexe
complex produs(complex x, complex y)
{
	complex z;
	z.a = x.a*y.a - x.b*y.b;
	z.b = x.a*y.b + x.b*y.a;
	return z;
}



void main()
{
	complex z1, z2;

	citire(&z1, "z1");
	citire(&z2, "z2");
	printf("\n");

	
	afisare(z1, "z1");
	afisare(z2, "z2");
	printf("\n");

	//modulele celor doua nr. complexe
	printf("Modulul lui z1: %.2f\n", modul(z1));
	printf("Modulul lui z2: %.2f\n", modul(z2));
	printf("\n");

	//conjugatele celor doua numere complexe
	afisare(conjugat(z1), "conjugat z1");
	afisare(conjugat(z2), "conjugat z2");

	//suma a doua nr. complexe - varianta 1
	complex s1;
	s1 = suma1(z1, z2);
	afisare(s1, "z1+z2");
	//suma a doua nr. complexe - varianta 2
	complex s2;
	suma2(z1, z2, &s2);
	afisare(s2, "z1+z2");

	//produsul a doua nr. complexe
	complex p;
	p = produs(z1, z2);
	afisare(p, "z1*z2");

	system("pause");
	return 0;
}