#include <stdio.h>

typedef struct datum{
    int ev;
    int honap;
    int nap;
}datum;

typedef struct ugyfel{
    int azonosito;
    char nev[30];
    char email[30];
    char telszam[30];
    int egyenleg;
    int kamat;
    datum date;
}ugyfel;


static ugyfel *adatok;
static int sorok;
static int ev;
static int honap;
static int nap;


int length(char *text)
{
    int hosszusag = 0;
    char *szoveg;
    szoveg = text;
    while(*szoveg != NULL)
    {
        *szoveg++;
        hosszusag++;
    }
    return hosszusag;
}

int compare(char *elso, char *masodik)
{
    int hossz1;
    int hossz2;
    hossz1 = length(elso);
    hossz2 = length(masodik);
    if(hossz1 != hossz2)
    {
        return 1;
    }
    else
    {
        char *egy;
        char *ketto;
        ketto = masodik;
        egy = elso;
        while(*egy != NULL)
        {
            egy++;
            ketto++;
            if(*egy != *ketto)
                return 1;
        }
    }
    return 0;
}


int datumbeolvasas()
{
    int year = 0;
    int month = 12;
    int day = 31;
    ev = year;
    honap = month;
    nap = day;
    char *ujra;
    int ellenorzes;
    printf("\n\nDatum (helyes formatum: 2021.11.17.): ");
    scanf("%d.%d.%d.", &year, &month, &day);
    ellenorzes = datumellenorzes(year, month, day);

    if(ellenorzes == 0)
    {
        printf("Szeretne megprobalni megegyszer? (i/n): ");;
        ujra = getch();
        if(ujra == 105)
        {
            datumbeolvasas();
        }
        else if(ujra == 110)
        {
            printf("\n");
            exit(0);
        }
        else
        {
            printf("\n\nHibas muvelet");
            printf("\nCsak az 'i' vagy az 'n' a helyes\n\n");
            datumbeolvasas();
        }
    }
}


int datumellenorzes(int *ev, int *honap, int *nap)
{
    int ellenorzes = 1;
    if((ev < 1900 || ev > 2021) || (honap < 1 || honap > 12) || (nap < 0 || nap > 31))
    {
        printf("\nHelytelen datum\n");
        ellenorzes = 0;
    }
    else if((honap == 4 || honap == 6 || honap == 9 || honap == 11) && nap > 30)
    {
        printf("\nMaximum 30 nap van ebben a a honapban\n");
        ellenorzes = 0;
    }
    else if(honap == 2 && nap > 28)
    {
        printf("\nFebruarban maximum 28 nap van\n");
        ellenorzes = 0;
    }
    return ellenorzes;
}

void beolvasas()
{
    FILE *fp;
    fp = fopen("lista.txt", "w");
    fprintf(fp, "Nev\t\tE-mail\t\tTelefonszam\tEgyenleg\tLekotes datuma\tKamat\n");
    fprintf(fp, "Bill Gates\tbg@gmail.com\t06206324999\t950000\t\t2018.11.15.\t4\n");
    fprintf(fp, "Elon Musk\ttesla@gmail.com\t06706124914\t990000\t\t2012.10.12.\t2\n");
    fprintf(fp, "Jeff Bezos\tjeff@gmail.com\t06201357963\t620000\t\t2016.02.02.\t3\n");
    fprintf(fp, "Mark Zuckerberg\tmz@gmail.com\t06306324911\t700000\t\t2017.04.04.\t4\n");
    fprintf(fp, "Mezei Mark\tmmr@gmail.com\t06207777712\t820000\t\t2014.12.24.\t10\n\n");
    fflush(fp);
    fclose(fp);
}

void opciok()
{
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\n1. UJ UGYFEL HOZZADASA\n");
    usleep(70000);
    printf("2. SAJAT PENZUGYEK\n");
    usleep(70000);
    printf("3. UTALAS\n");
    usleep(70000);
    printf("4. UGYFELLISTA\n");
    usleep(70000);
    printf("5. KIJELENTKEZES A PROGRAMBOL\n");
    usleep(70000);
    printf("6. GEP LEALLITASA\n");
    usleep(70000);
    printf("7. VALUTAVALTO\n");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
}

void ujugyfel()
{
    ugyfel adatok;
    int ellenorzes;
    char *again;
    printf("\nNev: ");
    gets(adatok.nev);
    ellenorzes = nevellenorzes(adatok.nev);
    while(ellenorzes != 1)
    {
        printf("\nErvenytelen nev\n");
        printf("Szeretne megprobalni megegyszer? (i/n): ");
        again = getch();
        if(again == 105)
        {
            printf("\n\nNev: ");
            gets(adatok.nev);
            ellenorzes = nevellenorzes(adatok.nev);
        }
        else if(again == 111)
        {
            printf("\n");
            return 1;
        }
        else
        {
            printf("\n\nHibas muvelet");
            printf("\nCsak az 'i' vagy az 'n' a helyes\n\n");
            return 1;
        }
    }



    printf("\nEmail: ");
    gets(adatok.email);
    ellenorzes = emailellenorzes(adatok.email);
    while(ellenorzes != 1)
    {
        printf("\nErvenytelen email\n");
        printf("Szeretne megprobalni megegyszer? (i/n): ");
        again = getch();
        if(again == 105)
        {
            printf("\n\nEmail: ");
            gets(adatok.email);
            ellenorzes = emailellenorzes(adatok.email);
        }
        else if(again == 110)
        {
            printf("\n");
            return 1;
        }
        else
        {
            printf("\n\nHibas muvelet");
            printf("\nCsak az 'i' vagy az 'n' a helyes\n\n");
            return 1;

        }
    }


    printf("\nTelefonszam: ");
    gets(adatok.telszam);
    ellenorzes = telszamellenorzes(adatok.telszam);
    while (ellenorzes != 1)
    {
        printf("\nErvenytelen telefonszam\n");
        printf("Szeretne megprobalni megegyszer? (i/n): ");
        again = getch();
        if(again == 105)
        {
            printf("\n\nTelefonszam: ");
            gets(adatok.telszam);
            ellenorzes = telszamellenorzes(adatok.telszam);
        }
        else if(again == 110)
        {
            printf("\n");
            return 1;
        }
        else
        {
            printf("\n\nHibas muvelet");
            printf("\nCsak az 'i' vagy az 'n' a helyes\n\n");
            return 1;
        }
    }


    char szamlaegyenleg[30];
    printf("\nEgyenleg: ");
    gets(szamlaegyenleg);
    sscanf(szamlaegyenleg, "%d", &adatok.egyenleg);


    int year;
    int month;
    int day;
    printf("\nA lekotes datuma: ");
    scanf("%d.%d.%d.", &year, &month, &day);
    ellenorzes = datumellenorzes(year, month, day);
    fflush(stdin);
    while (ellenorzes != 1)
    {
        printf("\nErvenytelen datum\n");
        printf("Szeretne megprobalni megegyszer? (i/n): ");
        again = getch();
        if(again == 105)
        {
            printf("\n\nA lekotes datuma: ");
            scanf("%d.%d.%d.", &year, &month, &day);
            ellenorzes = datumellenorzes(year, month, day);
        }
        else if(again == 110)
        {
            printf("\n");
            return 1;
        }
        else
        {
            printf("\n\nHibas muvelet");
            printf("\nCsak az 'i' vagy az 'n' a helyes\n\n");
            return 1;
        }
    }


    char kamat[10];
    printf("\nKamat: ");
    gets(kamat);
    sscanf(kamat, "%d\n", &adatok.kamat);

    printf("\n\nAz uj ugyfel neve: %s", adatok.nev);
    usleep(100000);
    printf("\nAz uj ugyfel email cime: %s", adatok.email);
    usleep(100000);
    printf("\nAz uj ugyfel telefonszama: %s", adatok.telszam);
    usleep(100000);
    printf("\nA szamla egyenlege: %d", adatok.egyenleg);
    usleep(100000);
    printf("\nA lekotes datuma: %d.%d.%d.", year, month, day);
    usleep(100000);
    printf("\nA kamat: %d", adatok.kamat);

}


void penzugyek()
{
    char nev[30];

hibas:
    printf("\nKerem az ugyfel nevet!: ");
    gets(nev);
    int n;
    n = 0;

    for(int i = 0; i < sorok; i++)
    {
        if(compare(nev,adatok[i].nev)== 0)
        {
            n = 1;
            break;
        }
    }
    if(n != 1)
    {
        printf("\nHIBAS NEV\n");
        goto hibas;
    }

    for(int i = 0; i < sorok; i++)
    {
        if(compare(nev,adatok[i].nev)== 0)
        {
            int eredmeny;
            system("cls");
            sleep(1);
            printf("%s penzugyi adatai:\n", nev);
            usleep(70000);
			printf("\nLekotes datuma: %d.%d.%d.\n",adatok[i].date.ev,adatok[i].date.honap,adatok[i].date.nap);
			usleep(70000);
            printf("Eves kamat: %d\n", adatok[i].kamat);
            usleep(70000);
			printf("Nyito egyenlege: %d\n", adatok[i].egyenleg);
			break;
        }
    }
}


void utalas()
{

    char utalo[30];
    char kezdemenyezo[30];
    char osszeg[20];
    int ossz;

ujra:
    printf("Az utalo neve: ");
    gets(utalo);
    printf("A kezdemenyezo neve: ");
    gets(kezdemenyezo);
    int k = 0;
    int u = 0;
    for(int i = 0; i < sorok; i++)
    {
        if(compare(kezdemenyezo,adatok[i].nev)== 0)
        {
            k = 1;
            break;
        }
    }
    for(int i = 0; i < sorok; i++)
    {
        if(compare(utalo,adatok[i].nev)== 0)
        {
            u = 1;
            break;
        }
    }
    if(k != 1 || u != 1)
    {
        puts("\nAz egyik vagy mindket nev hibas\n");
        goto ujra;
    }
hiba:
    printf("\nMennyit szeretnel utalni?\n");
    gets(osszeg);
    sscanf(osszeg, "%d", &ossz);
    for(int i = 0; i < sorok; i++)
    {
        if(compare(utalo,adatok[i].nev)== 0)
        {
            if(ossz > adatok[i].egyenleg)
            {
                printf("\nUTALAS...\n");
                sleep(2);
                printf("\nSIKERTELEN UTALAS\n");
                sleep(1);
                printf("\nNINCS ELEG EGYENLEG\n");
                goto hiba;
            }
            else
            {
                printf("\nUTALAS...\n");
                sleep(2);
                printf("\nSIKERES UTALAS\n");
                sleep(1);
            }
            break;
        }
    }
    for(int i = 0; i < sorok; i++)
    {
        if(compare(utalo,adatok[i].nev)== 0)
        {
            adatok[i].egyenleg -= ossz;
        }
        if(compare(kezdemenyezo,adatok[i].nev)== 0)
        {
            adatok[i].egyenleg += ossz;
        }
    }

}


int ugyfellista()
{
    FILE *fp;
    FILE *beolvas;
    fp = fopen("lista.txt", "w");

    fprintf(fp, "Nev\t\tE-mail\t\tTelefonszam\tEgyenleg\tLekotes datuma\tKamat\n");
    fprintf(fp, "Bill Gates\tbg@gmail.com\t06206324999\t950000\t\t2018.11.15.\t4\n");
    fprintf(fp, "Elon Musk\ttesla@gmail.com\t06706124914\t990000\t\t2012.10.12.\t2\n");
    fprintf(fp, "Jeff Bezos\tjeff@gmail.com\t06201357963\t620000\t\t2016.02.02.\t3\n");
    fprintf(fp, "Mark Zucki\tmz@gmail.com\t06306324911\t700000\t\t2017.04.04.\t4\n");
    fprintf(fp, "Mezei Mark\tmmr@gmail.com\t06207777712\t820000\t\t2014.12.24.\t10\n\n");

    fflush(fp);
    fclose(fp);

    beolvas = fopen("lista.txt", "r");
    char line[200];
    int sorok = 0;
    while(fgets(line, 200, beolvas))
    {
        sorok++;
    }
    fflush(fp);
    fclose(fp);
    return sorok-2;
}

void ugyfelek()
{
    FILE *beolvas;
    beolvas = fopen("lista.txt", "r");
    char line[200];
    int i = 0;
    fgets(line, 100, beolvas);
    while(fgets(line, 200, beolvas))
    {
        sscanf(line," %[^\t]\t%[^\t]\t%[^\t]\t%d\t\t%d.%d.%d.\t%d\n", adatok[i].nev, adatok[i].email,adatok[i].telszam,
        &adatok[i].egyenleg, &adatok[i].date.ev,&adatok[i].date.honap, &adatok[i].date.nap, &adatok[i].kamat);
        i++;
    }
    fflush(beolvas);
    fclose(beolvas);
}


void kilistaz()
{
    printf("Informacio lekerese...\n\n");
    sleep(2);

    for(size_t i = 0; i < sorok; i++)
    {
        usleep(250000);
        printf(" %s\t%s\t%s\t%d\t\t%d.%02d.%02d.\t%d\n",adatok[i].nev, adatok[i].email,adatok[i].telszam,
        adatok[i].egyenleg, adatok[i].date.ev, adatok[i].date.honap, adatok[i].date.nap, adatok[i].kamat);
    }
    sleep(1);
    printf("\nAz adatbazisban %d ugyfel szerepel\n\n", sorok);
}


void kijelentkezes()
{

    char IN;
    printf("\nBiztos ki akar jelentkezni? (i/n): ");
    IN = getch();
    system("cls");
    if(IN == 'i')
    {
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
        printf("\nKijelentkezes...\n");
        sleep(3);
        printf("\nA program leall...\n\n");
        sleep(2);
    }
    else if(IN == 'n')
    {
        megegyszer();
    }
    else
    {
        printf("\nHibas muvelet\n\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        megegyszer();
    }
}

void gepleallitas()
{
    char k;
    printf("\nBiztos leszeretne allitani a gepet?(i/n): ");
    printf("\n");
    k = getch();
    if(k == 105)
    {
        system("C:\\Windows\\System32\\shutdown.exe /s");
    }
    else if(k == 110)
    {
        megegyszer();
    }
    else
    {
        printf("\nHibas muvelet");
        megegyszer();
    }
}


void hatvanyozas(float *szam, int ev, float *szorzatszam)
{
	int i;
	float eredmeny = *(szam), hatvanyozas;
	hatvanyozas = *(szam);
	for (i = 1; i < ev; i++)
	{
		eredmeny *= hatvanyozas;
	}
	(*szorzatszam) = eredmeny;
}


void megegyszer()
{
    char muvelet;
    sleep(1);
    opciok();
    printf("\n\nKerjuk valasszon egy opciot!\n");

    muvelet = getch();
    printf("\nA(z) %c. opciot valasztotta\n\n", muvelet);
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
}


int beolvasasujra()
{

    char fajlnev[] = "lista.txt";

    char lista[30];


    printf("\nA BEOLVASANDO FAJL NEVE: ");
    scanf("%s", &lista);

    if(compare(lista,fajlnev) == 0)
    {
        printf("\nBEOLVASAS...\n");
        sleep(3);
        printf("\nA FAJL BEOLVASASA SIKERES\n");
        sleep(1);
        system("cls");
        megegyszer();
    }
    else
    {
        printf("\nBEOLVASAS...\n");
        sleep(3);
        printf("\nA FAJL BEOLVASASA SIKERTELEN");
        printf("\nNEM TALALHATO ILYEN FAJL\n\n");
        beolvasasujra();
    }
}



int emailellenorzes(char *email)
{
    int ellenorzes;
    int hosszusag;
    int pont = 0;
    int pontelott = 0;
    int pontutan = 0;
    int at = 0;
    char *szoveg;
    hosszusag = length(email);
    for(szoveg = email; *szoveg != NULL; szoveg++)
    {
        at++;
        if(*szoveg == '@')
        {
            break;
        }
    }
    for(szoveg = email; *szoveg != NULL; szoveg++)
    {
        pont++;
        if(*szoveg == '.')
        {
            break;
        }
    }
    for(szoveg = email; *szoveg != NULL; szoveg++)
    {
        if(pontelott == 1)
        {
            pontutan++;
        }
        if(*szoveg == '.')
        {
            pontelott = 1;
        }
    }
    if(at == 0 || at == hosszusag || at > pont || pont == 0 || pont == hosszusag || pontutan <= 1)
    {
        ellenorzes = 0;
    }
    else
    {
        ellenorzes = 1;
    }
    return ellenorzes;
}



int telszamellenorzes(char *telszam)
{
    int ellenorzes;
    int hossz;
    hossz = length(telszam);

    if (telszam[0] == '0' && telszam[1] == '6' && (telszam[2] == '2' || telszam[2] == '3' || telszam[2] == '7') && telszam[3] == '0' && hossz == 11)
    {
        ellenorzes = 1;
    }
    else
    {
        ellenorzes = 0;
    }
    return ellenorzes;
}



int nevellenorzes(char *nev)
{
	char *szoveg;
	int ellenorzes;
	int szokoz = 0;
	int szokozszam = 0;
	for (szoveg = nev; *szoveg != NULL; szoveg++)
	{
		if (szokoz == 1)
		{
            szokozszam++;
		}
		if (*szoveg == ' ')
		{
		    szokoz = 1;
		}
	}
	if (szokozszam < 2)
	{
	    ellenorzes = 0;
	}
	else
    {
        ellenorzes = 1;
    }
	return ellenorzes;
}


void valutavalto()
{
    float HUF;
    const float GBP = 0.0023;
    const float USD = 0.0031;
    const float EUR = 0.0027;
    const float CHF = 0.0029;
    const float RUB = 0.23;
    const float HRK = 0.021;
    const float CZK = 0.070;
    const float YEN = 0.35;
    const float RON = 0.014;
    const float WON = 3.64;

    printf("Irjon be egy osszeget amit atszeretne valtani!: ");
    scanf("%f", &HUF);

    printf("\n%.0f HUF --> %.2f GBP", HUF, HUF*GBP);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f USD", HUF, HUF*USD);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f EUR", HUF, HUF*EUR);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f CHF", HUF, HUF*CHF);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f RUB", HUF, HUF*RUB);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f HRK", HUF, HUF*HRK);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f CZK", HUF, HUF*CZK);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f YEN", HUF, HUF*YEN);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f RON", HUF, HUF*RON);
    usleep(70000);
    printf("\n%.0f HUF --> %.2f WON\n", HUF, HUF*WON);

}



