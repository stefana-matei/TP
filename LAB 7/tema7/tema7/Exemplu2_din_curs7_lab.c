/*Exemplu:
Se citesc de la tastatură numere până la introducerea valorii 0. 
Să se afișeze dacă toate numerele sunt pare, sau nu. Programul va utiliza doar strictul necesar de memorie. */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;    // cate numere sunt deja in vector

	// initializam v==NULL, deoarece aceasta va fi valoare pasata lui realloc
	// si daca v==NULL, realloc se va comporta ca malloc
	int *v = NULL;
	int *v2;    // variabila auxiliara pentru realloc


	for (;;) {    // bucla infinita pentru a citi toate numerele
		int k;

		printf("v[%d] = ", n);
		scanf("%d", &k);

		if (!k)
			break;   // daca s-a introdus 0, se iese din bucla
		// redimensioneaza v, pentru a avea loc noul element, k
		n++;

		if ((v2 = (int*)realloc(v, n * sizeof(int))) == NULL) {
			printf("memorie insuficienta\n");
			free(v);
			exit(EXIT_FAILURE);
		}
		v = v2;
		v[n - 1] = k;           // insereaza noul element la ultima pozitie in vectorul redimensionat
	}

	int i;
	int pare = 1;               // 1 daca toate numerele sunt pare, altfel 0


	for (i = 0;i < n;i++) {
		if (v[i] % 2 != 0) {     // daca s-a gasit un numar impar, se reseteaza "pare" si se iese din bucla
			pare = 0;
			break;
		}
	}


	if (pare)
		printf("\nToate numerele sunt pare!\n");
	else
		printf("\nExista si numere impare!\n");

	free(v);   // elibereaza memoria alocata pentru v


	system("pause");
	return 0;
}
