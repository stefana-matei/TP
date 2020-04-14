/*.In general struct si union se declara impreuna astfel omitand numele uniunii dar precizand numele membrilor din structura ce au 
tipul uniunii.Codul sursa din P2 va fi atunci : */

#include <stdio.h>
#include<conio.h>
#define tip_intreg 1
#define tip_real 2 

struct uniune_auxiliar
{
	char aux;
	union
	{
		int i;
		double r;
	} u;
};
int main()
{
	struct uniune_auxiliar uaux;
	uaux.u.i = 100;
	uaux.aux = tip_intreg;
	printf("%d %lf\n", uaux.u.i, uaux.u.r);
	uaux.u.r = 12.12;
	uaux.aux = tip_real;
	printf("%d %lf\n", uaux.u.i, uaux.u.r);

	system("pause");
	return 0;
}
