typedef struct {
	int valoare, putere;
}
factori;

int verificare_prim(int nr) {
	int i;
	for (i = 2; i < nr / 2 + 1; i++) {
		if (nr % i == 0) {
			return 0;
		}
	}

	return 1;
}

int descompunere(factori * set, int nr, int * count) {
	int i, k = 0;
	float root;
	for (i = 2; i < abs(nr) / 2 + 1; i++) {
		if (nr % i == 0) {
			if (verificare_prim(i)) 
				set[(*count)++].valoare = i;
		}
	}

	return (*count);
}

void afisare_factor(factori * set, int counter) {
	printf("\n%d", set[counter].valoare);
}

int main() {

	int number, n = 0, i;

	factori set[10];

	printf("Insert number: ");
	scanf("%d", &number);

	if (descompunere(set, number, &n)) {
		printf("\nPrime divisors are: \n");
		for (i = 0; i < n; i++) {
			afisare_factor(set, i);
		}
	}
	else {
		printf("\n%d is a prime number", number);
	}


	system("pause");
	return 0;

}