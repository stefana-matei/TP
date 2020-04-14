/*Se citeste de la tastatura un text scris pe mai multe randuri, cuvintele fiind despartite prin  unul din caracterele ” ,.;!”.
Sa se extraga cuvintele din text si apoi sa se afiseze alfabetic. Daca un cuvant apare de mai multe ori, el va fi scris o singura data.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>


void ordonare_alfab_sir(char s[])
{
	int i = 0, j, n;
	char a[50][20], aux[50], *c, sep[] = " ,.;!\n";
	c = strtok(s, sep);

	while (c != NULL)
	{
		strcpy(a[i], c);
		i++;
		c = strtok(NULL, sep);
	}

	n = i;
	for (i = 0;i < n - 1;i++)
		for (j = i + 1;j < n;j++)
			if (strcmp(a[i], a[j]) > 0) {
				strcpy(aux, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], aux);
			}

	for (i = 0;i < n;i++)
		printf("%s\n", a[i]);
}

int main()
{
	char sir[100];
	printf("Introduceti sirul \n");
	fflush(stdin);
	gets(sir);
	printf("Sirul ordonat este: \n");
	ordonare_alfab_sir(sir);
	system("pause");
	return 0;
}