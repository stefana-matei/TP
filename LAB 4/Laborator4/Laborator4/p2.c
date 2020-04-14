#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

void numar(char sir3[], char c)
{
	int i = 0, nr = 0;
	while (sir3[i] != '\0') //diferit de terminator de sir
	{
		if (sir3[i] == c)
			nr++; // numara caracterul de cate ori este in sir
		i++;
	}

	if (nr == 0)
		printf("Nu exista caracterul in sirul scris!\n");
	else
		printf("Numarul de caractere este %d\n", nr);
}

int main()
{
	char sir3[20];
	char c;//numar de caractere  c
	printf("Introduceti sirul : \n");
	gets(sir3);
	printf("\n\n");
	printf("Introduceti caracterul : \n");
	scanf("%c", &c);
	printf("\n");
	numar(sir3, c);
	system("pause");
	return 0;
}