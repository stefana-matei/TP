/*1.5. Se citeşte valoarea unui număr natural nr. 
Să se verifice si sa se afiseze dacă nr este sau nu este o putere a lui 2.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int nr;
	printf("dati nr :  ");
	scanf("%d", &nr);


	if ((nr & (nr - 1)) == 0)
		printf("%d este putere a lui 2\n", nr);
	else
		printf("%d nu este putere a lui 2\n", nr);

	system("pause");
	return 0;
}