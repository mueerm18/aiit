
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ANZAHL_DER_TOUREN 100



struct technischeDaten
{
    int steakenLaenge;
    int hoehenmeter;
    char nameDerRadtour[100];
};

struct Datum
{
    int tag;
    int monat;
    int jahr;
};

struct radTour
{
    struct Datum;
    struct technischeDaten;
};

void ausgabe(struct radTour gruppe[], int anzahl)
{

    printf("\nIhre Radtour:\n");
    printf("============");

    for(int i = 0; i < anzahl; i++)
    {
        printf("\n%d. %s   | %d.%d.%d  | %d %d ", i+1,gruppe[i].nameDerRadtour, gruppe[i].tag, gruppe[i].monat, gruppe[i].jahr, gruppe[i].steakenLaenge, gruppe[i].hoehenmeter);
    }
}

int eingabeGanzeZahl(char *text, int min, int max, int *zahl)
{

int ok = 0;
char s[100];

    do{
        if(!ok)
        {
          printf(" Bitte geben sie eine zahl zwischen %d und %d ein", min, max);
        }
        printf("%s", text);
        fgets(s, sizeof(s), stdin);
        fflush(stdin);
        if(s[0] == '<')
            return 0;
        ok = sscanf(s, "%d", zahl);
        ok &=(*zahl >= min) && (*zahl <= max);

    }while(!ok);

    return 1;
}

int eingabeText(char *textausgabe, char len, char *texteingabe)
{

    int ok = 1;
    char s[100];

    do{
         if(!ok){
          printf(" Ihre Eingabe ist zu lang. Bitte geben Sie einen Text mit maximal %d Zeichen ein \n", len);
        }
        if(textausgabe != NULL){
        printf(textausgabe);
        }
        fgets(s, len, stdin);
        fflush(stdin);
        if( s[0] == '<'){
            return 0;
        }
        ok = (strlen(s) > 0) && (strlen(s) < (len-1));
    }while(!ok);
    strcpy(texteingabe, s);
    texteingabe[strlen(s)-1] = '\0';
    return 1;
}

int eingabeDatum (struct Datum *fahrtDarum){

   int tag;
   int monat;
   int jahr;
   printf("Bitte geben Sie das Datum für die geplante Radtour ein: \n");

   if(eingabeGanzeZahl("jahr: ", 2000, 2022,  &jahr))
   {
      if(eingabeGanzeZahl("Monat: ", 1, 12, &monat))
      {
           if(eingabeGanzeZahl("Tag: ", 1, 31, &tag))
           {

              fahrtDarum->tag = tag;
              fahrtDarum->monat = monat;
              fahrtDarum->jahr = jahr;
              return 1;
           }
      }
   }
   return 0;
}



int eingabeRadtour (struct daten *datentour)
{

char nameDerTour[100];
int laenge = 0;
int hoehenmeter = 0;
int anzahl = 0;

printf("\n\n\tBitte geben Sie volgende Daten Ihrer Radtour ein: \n");

if(eingabeText("\nName der Radtour: ", nameDerTour, 100))
{
  if(eingabeGanzeZahl("\nLänge derRadtour: ", 0, 9999, laenge))
  {
    if(eingabeGanzeZahl("\nAnzahl der Fahrten: ", 0, 9999, anzahl))
    {
      if(eingabeGanzeZahl("\nHöhenmeter: ", 0, 9999, hoehenmeter))
      {

        strcpy(technischeDaten->name, nameDerTour);
        technischeDaten->laenge = laenge;
        technischeDaten->hoehe = hoehenmeter;
        technischeDaten->anzahl = anzahl;


        return 1;
        }
      }
    }
  }
  return 0;
}



int neueRadtour( struct radTour *tour, int *anzahl)
{

    if(!eingabeRadtour(&tour[*anzahl].technischeDaten))
    {
        return 0;

        if(!eingabeDatum(&tour[*anzahl].Datum))
        {
            return 0;
        }
    }


    printf("Neuer Radtour wurde Angelegt");
    *anzahl = *anzahl + 1;
}

int main (int argc, char** argv)
{


}


