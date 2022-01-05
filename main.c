#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "fuggveny1.h"


int main()
{
    setlocale(LC_ALL,"hu_HU");

    system("color 2");

    time_t ido;
    time(&ido);
    printf("%s",ctime(&ido));


    printf("\n------------------------------------------UDVOZOLJUK A BANKI ALKALMAZASBAN--------------------------------------------\n\n");


    datumbeolvasas();

    beolvasas();



    char fajlnev[] = "lista.txt";
    char lista[30];

    printf("\nA BEOLVASANDO FAJL NEVE: ");
    scanf("%s", &lista);
    if(compare(lista,fajlnev) == 0)
    {
        printf("\nBEOLVASAS...\n");
        sleep(2);
        printf("\nA FAJL BEOLVASASA SIKERES\n");
        sleep(1);
        system("cls");
    }
    else
    {
        printf("\nBEOLVASAS...\n");
        sleep(2);
        printf("\nA FAJL BEOLVASASA SIKERTELEN");
        printf("\nNEM TALALHATO ILYEN FAJL\n\n");
        char ujra;
        printf("Szeretne megprobalni megegyszer? (i/n): ");
        scanf("%s", &ujra);
        if (ujra == 'i')
            beolvasasujra();
        else if (ujra == 'n')
            printf("\nA program leall...");
        else
            printf("\nHibas muvelet");
            beolvasasujra();
    }


    fflush(stdin);

    sorok = ugyfellista();
    adatok = (ugyfel*)malloc(sorok*sizeof(ugyfel));
    if(!(adatok = (ugyfel*)malloc(sorok*sizeof(ugyfel))))
    {
        printf("\nNincs eleg memoria\n");
        exit(0);
    }
    ugyfelek();



    char muvelet;
    opciok();
    printf("\n\nKerjuk valasszon egy opciot!\n");
    muvelet = getch();
    printf("A(z) %c. opciot valasztotta\n\n", muvelet);
    puts("Kerjuk varjon...\n");
    sleep(2);

    switch(muvelet)
    {
            case '1':
                ujugyfel();
                megegyszer();
                break;
            case '2':
                penzugyek();
                megegyszer();
                break;
            case '3':
                utalas();
                megegyszer();
                break;
            case '4':
                kilistaz();
                megegyszer();
                break;
            case '5':
                kijelentkezes();
                break;
            case '6':
                gepleallitas();
                break;
             case '7':
                valutavalto();
                megegyszer();
                break;
            default:
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nHibas muvelet!\n");
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");
            megegyszer();

    }

    exit(0);


}
