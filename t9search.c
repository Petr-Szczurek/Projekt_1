#include <stdio.h>
#define radek 84
#define sloupec 100

int main ()
{
	// plneni kontaktu do pole
	int seznam [radek][sloupec];
	char znak = 'a';
	int row = 0;
	int col = 0;
	while (znak != EOF)
	{
		znak = getchar ();
		if (znak == EOF)
		{
			break;
		}
		if (znak == '\0') // posouva na dalsi radek
		{
			row++;
			col = 0; // reset sloupcu
		}
		seznam [row] [col] = znak; // zapis

		col++; // posouva na dalsi sloupec v poli
		printf ("%c", znak);
	}

	printf ("\n");

	int j;
	for (int i = 0; i < 6; i++)
	{
		for (j = 0; j < 19; j++)
		{
			printf ("%d", seznam [i][j]);
		}
	}
	
	return 0;
}
