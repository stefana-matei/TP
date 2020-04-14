#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define M_PI  3.14159265358979323846264338327950288


double unghigrade(int x0, int y0, int x1, int y1)
{
	double X, Y, distanta_puncte, unghi_radiani;
	X = x1 - x0;
	Y = y1 - y0;
	unghi_radiani= atan2((double)Y, (double)X);
	return  unghi_radiani * 180 / M_PI;//unghi in grade
}

int main() {
	int x0, y0, x1, y1;
	printf("Dati valori coordonatelor : \n");
	printf("x0 = ");
	scanf("%d", &x0);
	printf("y0 = ");
	scanf("%d", &y0);
	printf("x1 = ");
	scanf("%d", &x1);
	printf("y1 = ");
	scanf("%d", &y1);
	printf("Unghiul dintre segmentul celor doua puncte si axa Ox este : %.4lf\n", unghigrade(x0,y0,x1,y1));
	system("pause");
	return 0;
}