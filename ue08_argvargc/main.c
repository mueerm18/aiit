#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSortString(char **text, int anzahl)
{
  int i;
  char *h=NULL;

  for (i=0;i<anzahl-1;i++)
  {
    int j, tausch=0;
    for (j=0;j<anzahl-1-i;j++)
    {
      if (strcasecmp(text[j], text[j+1]) > 0)
      {
        h = text[j];
        text[j] = text[j+1];
        text[j+1] = h;
        tausch++;
      }
    }
    if (tausch==0)
      return;
  }
}


void printList(char **text, int anzahl)
{
    printf("Liste - Start\n");
    for (int i = 0; i < anzahl; ++i)
    {
        printf("\t%02d: %s\n", i+1, text[i]);
    }
    printf("Liste - Ende\n\n");
}

// int main (int argc, char** argv) {
int main (int argc, char* argv[])
{
    printf("argc= %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
      printf("  %d: %s\n", i, argv[i]);
    }

    char *feld[100];
    if (argc > 101) {
        printf("Fehler: Zu viele Argumente\n");
        return 1;
    }
    // Kopiere die Zeiger von argv ins eigene Feld
    int anzahl = argc - 1;
    for (int i = 0; i < anzahl; i++) {
      feld[i] = argv[i + 1];
    }

    if (anzahl)
    {
        bubbleSortString(feld, anzahl);
        printList(feld, anzahl);
    }


    return 1;
}

