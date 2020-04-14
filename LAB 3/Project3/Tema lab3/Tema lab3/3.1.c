/*Aplicația 3.1 : Să se citească de la tastatură două variabile de tip double (se citește cu %lf, nu cu %g!!!) 
și să se afișeze numele variabilei care se află la adresa cea mai mică de memorie utilizând pointeri.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double cel_mai_mic(double*point_a, double*point_b)
{
	if (point_a < point_b) {
		printf("a este variabila care se afla la adresa cea mai mica!\n");
		return *point_a;
	}
	else {
		printf("b este variabila care se afla la adresa cea mai mica!\n");
		return *point_b;
	}

}
int main() 
{
	double a, b;
	double*point_a = &a, *point_b = &b;


	printf("a = ");
	scanf("%lf", &a);
	printf("\n");

	printf("b = ");
	scanf("%lf", &b);
	printf("\n");

	printf("Un prim caz :\n ");
	printf("&a = %p\n &b = %p\n", point_a, point_b);
	cel_mai_mic(point_a, point_b);
	printf("\n\n");

	printf("Al doilea caz cu cei doi ponteri inversati: \n");
	point_b = &a;
	point_a = &b;
	printf("&a = %p\n &b = %p\n", point_a, point_b);
	cel_mai_mic(point_a, point_b);
	printf("\n");


	system("pause");
	return 0;
}