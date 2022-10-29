# Autor
Petr Szczurek

# O programu
1. program nacte vstup od uzivatele (neprerusene znaky 0-9) a ulozi jej do pole (maximalne 100 znaku)
2. dale program nacita jednotlive znaky ze souboru <seznam.txt>, uklada je do pole a porovnava je se znaky v poli od uzivatele
3. jakmile najde shodu tak ulozi zbytek znaku kontaktu (jmeno + cislo) do pole.
4. vytiskne dany kontakt a cely ciklus opakuje, dokud nenacte konec souboru
5. konec programu

# Info k typu programu
program funguje na zaklade hledani cisel i s prerusenou sekvenci libovolnych znaku mezi cisly.
pro upravu na verzi hledani znaku jdoucich posobe je nutne odkomentovat radek 117-124.

# Priklad spusteni

1. nezadam zadny argument k hledani:

    $%./t9search <seznam.txt 

- program vypise vsechny kontakty:

    Petr Dvorak, 603123456
    Jana Novotna, 777987654
    Bedrich Smetana ml., 541141120

2. zadam jeden argument: "7777"

    $%./t9search 7777 <seznam.txt

- vypise kontakt (program najde i takove kontakty, u kterych mezi kazdymi dvema nalezenymi znaky muze byt libovolna posloupnost jinych znaku)

    Jana Novotna, 777987654

# Priklady chybnych zadani

1. vice nez jedno cislo:
    $%./t9search 7777 12 <seznam.txt
    Spatne zadany vstup
2. znak misto cisla:
    $% ./t9search ahoj <seznam.txt
    Spatne zadany vstup - jine nez 0-9
3. vice nez 100 cisel:
    $% ./t9search 12212121247413851734817346341834183745174924293847128347384712947107544983475214613847923045872547111 <seznam.txt
    Prekrocena hranice cisel - max 100
4. 



