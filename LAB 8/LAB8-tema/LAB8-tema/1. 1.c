/*1. 1. Se consideră un număr natural reținut în variabila nr. Să se verifice dacă nr are valoare pară sau impară.*/

/*
Folosim operatorul &. Acesta va testa biţii. Dacă nr este impar, atunci reprezentarea sa în baza 2 va avea cel mai din dreapta bit pe 1.
De exemplu, nr = 11 se scrie în baza 2 ca 1101. Atunci 1011 & 1 = 1.
Dacă nr este par, atunci cel mai din dreapta bit va fi 0.
De exemplu, nr = 14 se scrie în baza 2 ca 1110. Atunci 1110 & 1 = 0.
Deci pentru orice număr nr, expresia nr & 1 furnizează ca rezultat cel mai din dreapta bit.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int nr;
	printf("dati nr :  ");
	scanf("%d", &nr);

	if ((nr & 1) == 1) // if (( nr & 1 ))
		printf("Numar impar\n\n");
	else
		printf("Numar par\n\n");

	system("pause");
	return 0;
}

// OBS  Operatorii pe biţi au o prioritate mică, de aceea se preferă o pereche suplimentară de paranteze în expresia instrucţiunii if.