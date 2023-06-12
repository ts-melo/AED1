
#include <stdio.h>
#include <string.h>

void main ()
{

	unsigned short casos, ql;
	unsigned short i, qc;
	unsigned short qtsLetra;
	unsigned sl;

	char vet[60];

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &ql);

		qc = 0;
		sl = 0;
		while (ql--)
		{

			scanf(" %s", vet);

			i = 0;
			qtsLetra = 0;

			while (vet[i])
			{

				sl += (vet[i] - 65) + qc + qtsLetra++;

				i++;

			}

			qc++;

			memset(vet, 0, sizeof(vet));
		}

		printf("%u\n", sl);

	}

}
