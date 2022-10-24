#include <stdio.h>

char preklad (char jmeno) // funkce na prelozeni znaku na cisla
{
	if (jmeno >= 'A' && jmeno <= 'Z')
	{
		jmeno += 32; 
	}
	if (jmeno == 'a'||jmeno == 'b'||jmeno == 'c'){
		jmeno = '2';}
	if (jmeno =='d'||jmeno == 'e'||jmeno == 'f'){
		jmeno = '3';}
	if (jmeno == 'g'||jmeno == 'h'||jmeno == 'i'){
		jmeno = '4';}
	if (jmeno == 'j'||jmeno == 'k'||jmeno == 'l'){
		jmeno = '5';}
	if (jmeno == 'm'||jmeno == 'n'||jmeno == 'o'){
		jmeno = '6';}
	if (jmeno == 'p'||jmeno == 'q'||jmeno == 'r'||jmeno == 's'){
		jmeno = '7';}
	if (jmeno == 't'||jmeno == 'u'||jmeno == 'v'){
		jmeno = '8';}
	if (jmeno == 'x'||jmeno == 'y'||jmeno == 'z'||jmeno == 'w'){
		jmeno = '9';}
	return jmeno;
}

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

	else if (argc > 2)
	{
		printf ("Spatne zadany vstup\n");
	}

	else
	{
		// zapis vstupu od uzivatele do pole (max 100 znaku)
		int i = 0;
		char vstupni_znak = 'a';
		char char_vstup [100]; // tu zapise vstup
		int pocitadlo = 0;
		int j = 0; // posouva znaky k porovnani
		char kontakt_na_tisk [100];
		int splneno = 0;
		int konec_radku = 0;
		int pocet_shod = 0;

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
			i++;
			vstupni_znak = argv[1][i];
		}

		while (znak != EOF) // porovnani vsech znaku
		{
			znak = getchar ();
			kontakt_na_tisk [pocitadlo] = znak;
			znak = preklad(znak);

			if (znak == char_vstup[j]) //posouvac 
			{
				j++;
			}
			else
			{
				j = 0;
				if (znak == char_vstup[j])
				{
					j++;
				}
			}
			if (j == i) // porovnavac shody
			{
				splneno++;
				j = 0;
			}
			if (znak == ' '	|| znak == '\0')
			{
				j = 0;
			}			
			if (znak == '\n') // reset po nacteni jmena a cisla
			{
				konec_radku++;
				if (konec_radku == 2)
				{
					pocitadlo = -1;
					konec_radku = 0;
				}
			}
			if (splneno == 1)
			{
				pocet_shod++;
				while (konec_radku != 2)
				{
					znak = getchar ();
					if (znak == EOF)
					{
						break;
					}
					if (znak == '\n')
					{
						konec_radku++;
						if (konec_radku == 2)
						{
							break;
						}
					}
					pocitadlo++;	
					kontakt_na_tisk [pocitadlo] = znak; 
				}
				printf ("%s\n", kontakt_na_tisk);					
				// reset
				pocitadlo = -1;
				konec_radku = 0;
				j = 0;
			}	

			splneno = 0;
			pocitadlo++;
		}
		
		if (pocet_shod == 0)
		{
			printf ("Nenalezeno\n");
		}		
	}
	
	return 0;
}
