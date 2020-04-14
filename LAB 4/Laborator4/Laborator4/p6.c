/*Se citeste de la tastatura un text scris pe mai multe randuri, cuvintele fiind despartite prin  unul din caracterele � ,.;!�.
Sa se extraga cuvintele din text si apoi sa se afiseze alfabetic. Daca un cuvant apare de mai multe ori, el va fi scris o singura data.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char text[100], *p, separator[] = " ,.;!", cuv[10][10], aux[10];
	int i, k, n;
	printf("Introduceti textul\n");
	fgets(text, 100, stdin);
	text[strlen(text) - 1] = NULL;
	p = strtok(text, separator);
	i = 0; n = 0;
	while (p)
	{
		strcpy(cuv[i], p);
		i++;
		n++;
		p = strtok(NULL, separator);
	}
	printf("Textul este format din urmatoarele cuvinte: \n");
	for (i = 0;i < n;i++)
		printf("%s ", cuv[i]);
	printf("\n");
	do
	{
		k = 1;
		for (i = 1;i < n;i++)
			if (strcmp(cuv[i - 1], cuv[i]) > 0)
			{
				strcpy(aux, cuv[i - 1]);
				strcpy(cuv[i - 1], cuv[i]);
				strcpy(cuv[i], aux);
				k = 0;
			}

	} while (!k);
	printf("Cuvintele ordonate alfabetic: \n");
	for (i = 0;i < n;i++)
		printf("%s ", cuv[i]);

	system("pause");
	return 0;
}