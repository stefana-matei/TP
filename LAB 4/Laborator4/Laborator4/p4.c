//cautare subsir intr-un sir

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100


int lungime(char(*str)[]) {
	int i;
	for (i = 0; (*str)[i] != '\0'; i++);
	return i;
}

void cautare_subsir(char(*sir)[], char(*subsir)[]) {

	int i, j, k = 0, lungime_sir, lungime_subsir, check;

	lungime_sir = lungime(&(*sir));
	lungime_subsir = lungime(&(*subsir));

	check = 0;
	for (i = 0; i < lungime_sir; i++) {
		for (j = 0; j < lungime_subsir && (*sir)[i + j] == (*subsir)[j]; j++) {
			if (++k == lungime_subsir) {
				check = 1;
			}
		}
	}

	if (check == 1) {
		printf("Subsirul se gaseste in sirul dat!\n");
	}
	else {
		printf("Subsirul nu se gaseste in sirul dat!\n");
	}
}


int main() {

	char s[MAX],sub[MAX];
	printf("Introduce sirul : ");
	gets(s);
	printf("\n");

	printf("Introdu subsirul : ");
	gets(sub);
	printf("\n");

	cautare_subsir(&s,&sub);
	printf("\n");
	system("pause");
	return 0;
}