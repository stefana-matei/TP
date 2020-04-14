/*Atentie: unele dintre programe pot fi scrise intenționat greșit, pentru a evidenția greșeli care se
 fac în mod tipic!*/


 //TEST 3 - este gresit !!!!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
	int *x, *z;
	x = z = (int *)malloc(7 * sizeof(int));
	if (!x) {
		printf("Eroare alocare 1.\n");
		exit(EXIT_FAILURE);
	}
	free(x);
	free(z);
	return 0;
}



// VARIANTA BUNA


//int main(void)
//{
	//int *x, *z;
	//x = (int *)malloc(7 * sizeof(int));
	//z = (int *)malloc(7 * sizeof(int));

	//if (x == NULL) {
	//	printf("Eroare alocare 1.\n");
	//	exit(EXIT_FAILURE);
	//}

	//if (z == NULL) {
	//	printf("Eroare alocare 2!\n");
	//	exit(EXIT_FAILURE);
	//}

	//free(x);
//	free(z);

//	system("pause");
//	return 0;
//}