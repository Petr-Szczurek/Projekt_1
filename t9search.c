#include <stdio.h>

int main (int argc, char *argv[])
{
	
	// kontrola zadaneho cisla
	char znak = 'a';
	// printf ("%d", argc); //pocet argumentu jsou 2 pokud zadam cislo
	if (argc < 2) 
    {
		while (znak != EOF) // vytiskne seznam pokud uzivatel nezada zadne cislo
		{
			znak = getchar ();
			if (znak == EOF)
			{
				break;
			}
			printf ("%c", znak);
		}
		printf ("\n");
    }
	else if (argc == 2)
	{
		// zapis vstupu od uzivatele do pole (max 100 znaku)
		int i = 0;
		char vstupni_znak = 'a';
		char char_vstup [100];
		while (vstupni_znak != '\0')
		{
			if (argv[1][i] <= '0' || argv[1][i] >= '9') //kontroluje zda se jedna o 0-9 znaky
			{
				printf ("Spatne zadany vstup - jine nez 0-9\n");
				return 1;
			}
			if (i == 100) // kontroluje pocet zadanych znaku
			{
				printf ("\n");
				printf ("Prekrocena hranice cisel - max 100\n");
				return 1;
			}
			
			char_vstup [i] = argv[1][i];
			// printf ("%c", char_vstup [i]);
			i++;
			vstupni_znak = argv[1][i];
		}
		// printf ("\n");

		while (znak != EOF) // porovnani vsech znaku
		{
			znak = getchar ();
			if (znak == EOF)
			{
				break;
			}
		}
		

	}
	else
	{
		printf ("Spatne zadany vstup\n");
	}

	return 0;
}
