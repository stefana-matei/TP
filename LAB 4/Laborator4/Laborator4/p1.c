#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

void numar(char s[])
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	printf("Numarul de caractere : %d\n", i);
}

int main()
{
	char s[20];
	printf("Introduceti sirul \n");
	gets(s);
	numar(s);
	system("pause");
	return 0;
}