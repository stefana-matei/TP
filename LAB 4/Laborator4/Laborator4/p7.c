/*Se citeste de la tastatura un text de maxim 250 caractere. Sa se separe constantele zecimale intregi
si sa se calculeze suma acestora(fiecare constanta va avea lungimea pana la 20 de cifre zecimale).*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>


int suma_constzec_sir(char s[])
{
	int i = 0, ok = 1, sum = 0, S = 0;

	for (i < 0;i < strlen(s);i++)
	{
		sum = 0;
		if (s[i] >= '0'&& s[i] <= '9')
		{
			ok = 1;
			sum = s[i] - '0';
			while (ok == 1)
			{
				if (s[i + 1] >= '0'&& s[i] <= '9')
				{
					sum = sum * 10 + (s[i + 1] - '0');
					i++;
				}
				else 
					ok = 0;
			}
		} S += sum;
	}

	return S;
}

int main()
{
	char s[100];
	printf("Introduceti sirul \n");
	fflush(stdin);
	gets(s);
	printf("\n");	
	
	printf("Suma numerelor din sir este: ");
	printf("%d", suma_constzec_sir(s));
	printf("\n");

	system("pause");
	return 0;
}