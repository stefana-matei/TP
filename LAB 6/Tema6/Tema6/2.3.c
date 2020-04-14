/*Aplicația 2.3: Se citește de la tastatură o linie de text care conține o atribuire a unei variabile cu o valoare.
Linia are forma ”nume_variabila=valoare”. Numele variabilei poate conține doar litere sau cifre, cu restricția ca
primul caracter să fie literă. Valoarea poate fi număr (începe cu o cifră și poate avea zecimale), caracter 
(începe cu apostrof) sau șir de caractere (începe cu ghilimele). Câteva exemple de astfel de atribuiri:
raza=10.12
B22 = 'c'
adresa="Bd. Vasile Parvan nr. 2"
Folosind struct și union definiți o structură de date pentru a păstra în mod eficient 
informația din linia citită de la tastatură. Transferați informația din linia citită într-o variabilă de tipul structurii 
de date definite. Afișați informația păstrată în variabilă, folosind formatul original (nume_variabila=valoare). 
Tratați posibile erori ce pot să apară în linia citită (nume incorect de variabilă, lipsește semnul egal,
valoarea atribuită este invalidă).
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 30

typedef struct {
	char nume[7];
} tip;

typedef struct {
	char nume[MAX],valoare_stocata[MAX];
	tip tipul;
} string;

typedef struct {
	char nume[MAX],	valoare_stocata;
	tip tipul;
} ch;

typedef struct {
	char nume[MAX];
	float valoare_stocata;
	tip tipul;
} real;

typedef struct {
	char nume[MAX];
	int valoare_stocata;
	tip tipul;
} integer;

typedef union {
	string strings;
	ch chars;
	real reals;
	integer ints;
} tipuri_variabile;

int potrivire(char *str, char ch) {

	int i, k = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == ch) 
			k++;
	}
	return k;
}

void shift(char *str, int times) {
	int i = 0;
	for (i = 0; str[i + times] != '\0'; i++) {
		str[i] = str[i + times];
	}
	str[i] = '\0';
}

void trim(char *str, char ch) {
	int i;
	for (i = 0; str[i] != '\0'; i++);

	while (str[--i] == ch) {
		str[i] = '\0';
	}
	i = -1;
	while (str[++i] == ch)
		;
	shift(str, i);
}

void typeOf(char *str, char *tipul) {
	int i,string = 0, real = 0;
	strcpy(tipul, "integer");

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.') {
			real++;
		}
		if (real != 1 && (str[i] == ' ' || str[i] > '9' || str[i] < '0')) {
			string++;
		}
	}
	if (string) {
		if (strlen(str) == 1 || (str[0] == 39 && str[2] == 39)) {
			strcpy(tipul, "char");
		}
		else
			strcpy(tipul, "string");
	}
	else if (real)
		strcpy(tipul, "float");
}
void extractValue(char *str, char *tipul) {
	int i = strlen(str);

	typeOf(str, tipul);

	if ((str[0] == 34 && str[i - 1] == 34) || (str[0] == 39 && str[i - 1] == 39)) {
		str[i - 1] = '\0';
		shift(str, 1);
	}
}

int validateName(char *str) {
	int i;
	if (!((str[0] <= 'z' && str[0] >= 'a') ||(str[0] <= 'Z' && str[0] >= 'A'))) {
		return 0;
	}
	for (i = 0; str[i] != '\0'; i++) {
		if (!(
			(str[i] <= 'z' && str[i] >= 'a') ||
			(str[i] <= 'Z' && str[i] >= 'A') ||
			(str[i] <= '9' && str[i] >= '0')
			)) {
			return 0;
		}
	}

	return 1;
}

int split(char *str, char *nume, char *valoare_stocata) {
	int i, k = 1;
	for (i = 0; str[i] != '='; i++, k++) {
		nume[i] = str[i];
	}
	nume[i] = '\0';
	trim(nume, ' ');
	if (!validateName(nume)) {
		printf("\nInvalid name!");
		return 0;
	}
	else {
		for (i = 0; str[i] != '\0'; i++) {
			valoare_stocata[i] = str[i + k];
		}
		trim(valoare_stocata, ' ');
		extractValue(valoare_stocata, str);
	}
	return 1;
}

void citire(tipuri_variabile *record, int *count) {
	char input[MAX],nume[MAX],valoare_stocata[MAX];
	printf("\n Introduceti : ");
	while (getchar() != '\n')
		;
	scanf("%[^\n]s", input);

	if (!potrivire(input, '=')) {
		printf("\nNu se poate!Lipseste operatorul '=' !\n");
	}
	else if (split(input, nume, valoare_stocata)) {
		(*count)++;
		switch (input[0]) {
		case 's':
			strcpy(record[*count].strings.nume, nume);
			strcpy(record[*count].strings.valoare_stocata, valoare_stocata);
			strcpy(record[*count].strings.tipul.nume, input);
			printf("\nRecord %d:\nNume: %s\nValoare: %s\nTip :  %s\n",(*count) + 1,record[*count].strings.nume,record[*count].strings.valoare_stocata,record[*count].strings.tipul.nume);
			break;


		case 'c':
			strcpy(record[*count].chars.nume, nume);
			record[*count].chars.valoare_stocata = valoare_stocata[0];
			strcpy(record[*count].chars.tipul.nume, input);
			printf("\nRecord %d:\nNume: %s\nValoare: %c\nTip : %s\n",(*count) + 1,record[*count].chars.nume,record[*count].chars.valoare_stocata,record[*count].chars.tipul.nume);
			break;


		case 'i':
			strcpy(record[*count].ints.nume, nume);
			record[*count].ints.valoare_stocata = atoi(valoare_stocata);
			strcpy(record[*count].ints.tipul.nume, input);
			printf("\nRecord %d:\nNume: %s\nValoare: %d\nTip : %s\n",(*count) + 1,record[*count].ints.nume,record[*count].ints.valoare_stocata,record[*count].ints.tipul.nume);
			break;


		case 'f':
			strcpy(record[*count].reals.nume, nume);
			record[*count].reals.valoare_stocata = atof(valoare_stocata);
			strcpy(record[*count].reals.tipul.nume, input);
			printf("\nRecord %d:\Nume: %s\nValoare: %f\nTip : %s\n",(*count) + 1,record[*count].reals.nume,record[*count].reals.valoare_stocata,record[*count].reals.tipul.nume);
			break;
		}
	}

}


int main() {
	tipuri_variabile x[10];
	int optiune, count = -1, i;


	while (1) {
		printf("0.Iesire");
		printf("\n1. Citire");
		printf("\nOptiunea dvs. : ");
		scanf("%d", &optiune);
		switch (optiune) {
		case 0:
			return 0;
		case 1:
			citire(x, &count);
			break;
		default:
			printf("\nNu exista optiunea aleasa!\n");
			break;
		}
	}

	system("pause");
	return 0;
}