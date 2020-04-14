/*Aplicația 2.6: Să se codifice următoarele informații despre un medicament, astfel încât ele să ocupe în total un singur octet.
Să se scrie un program care să citească datele unui medicament și ulterior să le afișeze.
•	gradul de periculozitate: scăzută, medie, mare
•	dacă se eliberează doar pe bază de rețetă: da, nu
•	vârsta minimă de administrare: 1...18 ani inclusiv
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

typedef enum {scazuta,medie,mare }grad_periculozitate;

typedef struct{
	
	unsigned int eliberare_reteta : 2; 
	unsigned int varsta_minima : 5;
	grad_periculozitate gradul_de_periculozitate ;
	
}Medicament;

int main() 
{
	Medicament m;
	int aux_grad;
	unsigned int aux_eliberare_reteta,aux_varsta_minima;

	printf(" Marimea structurii este = %d\n\n", sizeof(m));

	//citire date
	printf("Informatii despre un medicament : \n");

	printf("Grad de periculozitate (0) Scazuta  (1) Medie   (2) Mare  :  ");
	scanf("%d", &aux_grad);
	m.gradul_de_periculozitate = aux_grad;
	
	printf("Se elibereaza pe baza de reteta? (DA sau NU) : ");
	scanf("%u", &aux_eliberare_reteta);
	m.eliberare_reteta = aux_eliberare_reteta;

	printf("Varsta minima de adminstrare : ");
	scanf("%d", &aux_varsta_minima);
	m.varsta_minima = aux_varsta_minima;


	printf("\n\n");


	//afisare
	printf("Datele citite despre medicament : \n\n");


	printf("\tGradul de periculozitate : ");
	
	if (m.gradul_de_periculozitate == 0)
		printf("Scazuta\n");
	else if (m.gradul_de_periculozitate == 1)
		printf("Medie\n");
	else
		printf("Mare\n");


	if (m.eliberare_reteta)
		printf("\tSe elibereaza doar pe baza de reteta!\n");
	else
		printf("\tNu se elibereaza pe baza de reteta!\n");

	printf("\tVarsta minima : %u\n\n ", m.varsta_minima);

	system("pause");
	return 0;

}