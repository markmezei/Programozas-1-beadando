#include "fuggveny.c"

static ugyfel *adatok;
static int sorok;
static int ev;
static int honap;
static int nap;
int length();
int compare(char *elso, char *masodik);
int datumbeolvasas();
int datumellenorzes();
void opciok();
void ujugyfel();
void penzugyek();
void utalas();
int ugyfellista();
void ugyfelek();
void kilistaz();
void kijelentkezes();
void gepleallitas();
void hatvanyozas(float *szam, int ev, float *szorzatszam);
void megegyszer();
int beolvasasujra();
int emailellenorzes(char *email);
int telszamellenorzes(char *telszam);
int nevellenorzes(char *nev);
void valutavalto();

