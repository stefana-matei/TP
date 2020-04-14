/*Atentie: unele dintre programe pot fi scrise intenționat greșit, pentru a evidenția greșeli care se
 fac în mod tipic!*/


//TEST 2 - este gresit,ar trebui folosita functia realloc pentru variabila x
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{
	int *x;
	x = (int *)malloc(7 * sizeof(int));

	if (!x) {
		printf("Eroare alocare 1.\n");
		exit(EXIT_FAILURE);
	}

	x = (int *)malloc(24 * sizeof(int));

	if (!x) {
		printf("Eroare alocare 2.\n");
		exit(EXIT_FAILURE);
	}


	free(x);

	system("pause");
	return 0;
}


// VARIANTA BUNA


//int main(void)
//{
	//int *x, *y;
	//x = (int *)malloc(7 * sizeof(int));

	//if (x == NULL) {
	//	printf("Eroare alocare 1.\n");
	//	exit(EXIT_FAILURE);
	//}

	//y = (int *)malloc(24 * sizeof(int));
	//if (y == NULL) {
	//	printf("Eroare alocare 2!\n");
	//	exit(EXIT_FAILURE);
	//}

	//free(x);
	//free(y);

//	system("pause");
//	return 0;
//}
