/*Declararea unei înregistrări şi folosirea acesteia*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

typedef struct
{
	long int numar_inregistrare;
	char* titlu;
	char* autor;
	struct
	{
		int anul_fabricatiei;
		char* editura;
	}editia;

	float pret;
}librarie;



int main()
{
	librarie carte1;
	carte1.numar_inregistrare = 256708;
	carte1.titlu = " Jurnalul adolescentului miop ";
	carte1.autor = "Mircea Eliade";
	carte1.editia.anul_fabricatiei = 1989;
	carte1.editia.editura = "Minerva";
	carte1.pret = 35.67;


	printf("Numar inregistrare: %d\n", carte1.numar_inregistrare);
	printf("Titlu : %s\n", carte1.titlu);	
	printf("Autor : %s\n", carte1.autor);
	printf("Aparitie : an %d prima editura %s\n", carte1.editia.anul_fabricatiei,carte1.editia.editura);
	printf("Pret : %.2f\n", carte1.pret);
	
	system("pause");
	return 0;
}