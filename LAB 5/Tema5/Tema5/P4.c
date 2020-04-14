/*Se citesc de la tastatură și se afișează pe ecran următoarele informații despre autovehicul: marca, tipul 
(pentru transport persoane sau pentru transport marfă), numărul de km parcurși, tipul de carburant (diesel/benzina) și 
capacitatea (numărul de locuri la transportul de persoane și tonajul la transportul de marfă).
Programul va prelucra informații despre un autovehicul, folosind alocarea dinamica a memoriei*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define tpers 1
#define tmarfa 2


struct autovehicul
{
	char aux;
	union
	{
		int locuri;
		double tonaj;
	} capacitate;

	float km;
	char diesel;
	char marca[];
};




void linii()
{
	int car;
	while ((car = getchar()) != EOF && car != '\n');
}


int main()
{
	struct autovehicul *autovehicul;
	char buffer[100];  // Buffer temporar pentru a citi marca, inainte de a face alocare dinamica.

	printf("Marca :  ");
	fgets(buffer, 100, stdin);  // Scapam de  terminator limie '\n' citit de fgets.
	

	buffer[strlen(buffer) - 1] = 0;   
	
	// Alocam dinamic memorie. Includem spatiul pentru a memora marca.
	autovehicul = (struct autovehicul *)malloc(sizeof(struct autovehicul) + strlen(buffer) + 1);

	if (!autovehicul) {
		printf("Eroare alocare memorie.\n");
		exit(EXIT_FAILURE);
	}

	//Transferam marca in zona alocata dinamic. */
	strcpy(autovehicul->marca, buffer);
	printf("Tip (P - persoane, altceva - marfa)? ");
	fgets(buffer, 100, stdin);
	if (toupper(buffer[0]) == 'P')
		autovehicul->aux = tpers;
	else
		autovehicul->aux = tmarfa;
	if (autovehicul->aux == tpers)
	{
		printf("Nr. locuri? ");
		scanf("%d", &autovehicul->capacitate.locuri);
	}
	else
	{
		printf("Tonaj : ");
		scanf("%lf", &autovehicul->capacitate.tonaj);
	}

	printf("km parcursi : ");
	scanf("%f", &autovehicul->km);

	//Sarim peste toate caracterele pana la (inclusiv)'\n'
	linii();
	printf("Diesel (D - da, altceva - nu)? : ");
	fgets(buffer, 100, stdin);
	if (toupper(buffer[0]) == 'D')
		autovehicul->diesel = 1;
	else
		autovehicul->diesel = 0;


	//Afisam datele citite. */
	printf("\nMarca: %s\n", autovehicul->marca);
	if (autovehicul->aux == tpers)
		printf("Transport persoane: %d locuri\n", autovehicul->capacitate.locuri);
	else
		printf("Transport marfa: %.2lf tone\n", autovehicul->capacitate.tonaj);
	printf("%.2f km parcursi\n", autovehicul->km);
	if (autovehicul->diesel)
		printf("Diesel\n");
	else
		printf("Benzina\n");


	// Eliberam memoria alocata dinamic.
	free(autovehicul);

	system("pause");
	return 0;
}
