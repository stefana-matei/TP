/*4) Să se realizeze o aplicaţie pentru lucrul cu numere raţionale (valori numerice ce pot fi scrise sub formă de fracţie) şi anume:
citirea, afişarea, sumarea şi produsul a două numere astfel de numere*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>


int a, b;


int cmmdc(int x, int y)
{
	if (x == y) 
		return x;
	else
		if (x > y) 
			return cmmdc(x - y, y);
		else
			return cmmdc(x, y - x);
}


void ireductibil()
{
	if (b < 0) {
		a = -a;
		b = -b;
	}

	if (!a)
		b = 1;
	else if (abs(a) != 1 && abs(b) != 1) {
			int d = cmmdc(abs(a), abs(b));
			a = a / d;
			b = b / d;
	}
}


typedef struct
{
	int x, y;

}rational;


void citire(rational* r, char c)
{
	printf("Citire numar rational %c :\n", c);
	printf("numaratorul: ");
	scanf("%d", &r->x);

	int n;
	do{
		printf("numitorul: ");
		scanf("%d", &n);
	} while (n == 0);

	r->y = n;
	ireductibil();
}


void afisare(rational r, char c[])
{
	printf("Numarul rational %s: %d/%d\n", c, r.x, r.y);
}


rational adunare(rational r1, rational r2)
{
	rational r;
	r.x = r1.x*r2.y + r1.y*r2.x;
	r.y = r1.y*r2.y;
	ireductibil();
	return r;
}


rational inmultire(rational r1, rational r2)
{
	rational r;
	r.x = r1.x*r2.x;
	r.y = r1.y*r2.y;
	ireductibil();
	return r;
}


void main()
{
	rational x, y;

	citire(&x, 'x');
	printf("\n\n");
	citire(&y, 'y');

	printf("\n");
	afisare(x, "x");
	afisare(y, "y");
	
	printf("\n\n");
	rational s;
	s = adunare(x, y);
	afisare(s, "x+y");

	printf("\n");
	rational p;
	p = inmultire(x, y);
	afisare(p, "x*y");

	printf("\n\n");

	system("pause");
	return 0;
}

