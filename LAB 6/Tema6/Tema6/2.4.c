/*Aplicația 2.4: Folosind câmpuri pe biți, definiţi o structură pentru memorarea următoarelor informaţii despre animale:
•	numărul de picioare: număr întreg, minim 0 (ex. şarpe), maxim 1000 (ex. miriapod)
•	greutatea în kg: număr real
•	periculos pentru om: da/nu
•	abrevierea ştiinţifică a speciei: şir de maxim 8 caractere
•	vârsta maximă în ani: număr întreg, minim 0, maxim 2000
Unde este posibil, codificaţi informaţiile prin numere întregi de dimensiune cât mai mică, spre exemplu “da”=1, “nu”=0. 
Definiţi structura în aşa fel încât să ocupe spaţiul minim de memorie posibil. 
Afişaţi spaţiul de memorie ocupat, folosind operatorul sizeof. 
Folosind structura definită, citiţi de la tastatură informaţii despre un animal, iar pe urmă afişaţi-le pe ecran.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>


typedef struct animal {
	unsigned int periculos : 1; /*(0)NU (1)DA*/
	unsigned int numar_picioare : 11;
	unsigned int varsta : 11;
	char abreviere_stiintifica[10];
	float greutate;
	
}animal;

int main() {
	unsigned int aux;
	char aux2[80];
	struct animal a;
	int l, i;

	printf(" Marimea structurii este = %d\n\n", sizeof(struct animal));
	
	//citire date
	printf("Introduceti numarul de picioare : ");
	scanf("%u", &aux);
	a.numar_picioare = aux;

	printf("Introduceti greutatea in kg : ");
	scanf("%f", &a.greutate);

	printf("Este animalul periculos pentru om? (0)NU (1)DA : ");
	scanf("%u", &aux);
	a.periculos = aux;

	printf("Abrevierea stiintifica : ");
	scanf("%s", &aux2);
	l = strlen(aux2);

	for (i = 0;i < l;i++)
		a.abreviere_stiintifica[i] = aux2[i];

	printf("Varsta maxima : ");
	scanf("%u", &aux);
	a.varsta = aux;

	printf("\n\n");


	//afisare
	printf("Datele citite despre animal : \n\n");
	printf("\tAbreviere stiintifica : ");
	for (i = 0;i < l;i++)
		printf("%c", a.abreviere_stiintifica[i]);
	printf("\n\tNumar picioare : %u\n", a.numar_picioare);
	printf("\tGreutate : %.3f kg \n", a.greutate);

	if (a.periculos)
		printf("\tEste periculos\n");
	else
		printf("\tNu este periculos\n");
	
	printf("\tVarsta : %u\n\n", a.varsta);


	system("pause");
	return 0;

}