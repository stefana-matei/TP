//functie care compara doua siruri de caractere sir1 cu sir 2

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

void comparare_siruri(char sir1[], char sir2[])
{
	int i;
	for (i = 0; sir1[i] == sir2[i] && sir1[i] == '\0'; i++);

	if (sir1[i] < sir2[i])
		printf("Al doilea sir este mai mare!\n");
	else if (sir1[i] > sir2[i])
		printf("Primul sir este mai mare!\n");

	else
		printf("Cele doua siruri sunt egale!\n");

}

int main()
{
	char sir1[20], sir2[20];
	printf("Introduceti sirul 1 \n");
	gets(sir1);
	printf("\n");

	printf("Introduceti sirul 2 \n");
	gets(sir2);
	printf("\n");

	comparare_siruri(sir1, sir2);

	system("pause");
	return 0;
}