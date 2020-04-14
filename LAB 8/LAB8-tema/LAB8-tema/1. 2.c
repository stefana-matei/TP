/*1. 2. Se citeşte valoarea unui număr natural nr <= 15. Să se afişeze valoarea 2 la puterea nr.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int nr;
	printf("dati nr :  ");
	scanf("%d", &nr);
	printf(" 2 ^ %d = %d\n\n", nr,(1 << nr)); //echivalent cu 2^nr 

	system("pause");
	return 0;
}