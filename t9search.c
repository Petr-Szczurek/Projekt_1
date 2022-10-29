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

void vypis_shodnych_kontaktu (int pocitadlo, char kontakt_na_tisk []) // funkce vypisuje shodne kontakty
{
	for (int w = 0; w <= pocitadlo; w++)
	{
		printf ("%c", kontakt_na_tisk [w]);
	}
	printf ("\n");	
}

int main (int argc, char *argv[])
{
	char znak = 'a';
	// kontrola argumentu (zadaneho cisla) 
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
		int i = 0; // pocatecni hodnota pro posun v poli + pocet zadanych znaku
		char vstupni_znak = 'a'; 
		char char_vstup [100]; // zapise zadany vstup od uzivatele
		int pocitadlo = 0; // posova prvky v poli
		int j = 0; // posouva vstupni argumenty k porovnani
		char kontakt_na_tisk [100]; // pole znaku (jmeno + cislo kontaktu), ktere kdyz je shoda tak vytiskne
		int splneno = 0; // kontrola shody
		int konec_radku = 0; // pocitadlo na konce radku
		int pocet_shod = 0; // kontrola na shody v porovnani vsech znaku

		while (vstupni_znak != '\0') // zapis vstupu od uzivatele do pole (max 100 znaku)
		{
			if (argv[1][i] < '0' || argv[1][i] > '9') //kontroluje zda se jedna o 0-9 znaky
			{
				printf ("Spatne zadany vstup - jine nez 0-9\n");
				return 1;
			}
			if (i == 100) // kontroluje pocet zadanych znaku
			{
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
			}

			if (znak == '\n') // reset po nacteni kontaktu (jmeno + cislo)
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
				splneno = 0;

				while (1) // dopise do pole ostatni znaky nehlede na dalsi shody
				{
					znak = getchar ();
					if (znak == EOF) // pripad posledniho kontaktu
					{
						vypis_shodnych_kontaktu (pocitadlo, kontakt_na_tisk);
						return 0;
					}
					if (znak == '\n')
					{
						konec_radku++;
						if (konec_radku == 2)
						{
							vypis_shodnych_kontaktu (pocitadlo, kontakt_na_tisk);
							// reset
							pocitadlo = -1;
							konec_radku = 0;
							break;
						}
					}
					pocitadlo++;
					kontakt_na_tisk [pocitadlo] = znak;
				}
			}
			pocitadlo++;
		}
		
		if (pocet_shod == 0)
		{
			printf ("Nenalezeno\n");
		}		
	}
	
	return 0;
}
