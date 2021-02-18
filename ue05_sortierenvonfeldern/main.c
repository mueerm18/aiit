#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Ganzzahlige ZZ berechnen
int berechneGanzeZZ(int ug, int og)
{
  return rand() % (og-ug+1) + ug;
}

// FK ZZ berechnen
double berechneFkZZ(double ug, double og)
{
  return ug + (og-ug) * rand() / RAND_MAX;
}

// Feld erstellen mit 20 bis 60 Zahlen zwischen 50 und 250
int feldErstellen(double f[])
{
  int i, anzahl = berechneGanzeZZ(20,60);
  for (i=0;i<anzahl;i++)
    f[i] = berechneFkZZ(50.0,250.0);
  return anzahl;
}

// Feld ausgeben in 10 Spalten mit 3 NKS
void feldAusgabe(char* txt, double f[], int anzahl)
{
  int i;
  printf("%s\n", txt);
  for (i=0;i<anzahl;i++)
    printf("%8.3lf", f[i]);
  printf("\n");
  if ((anzahl % 10) > 0)
    printf("\n");
}

// Vertauschen zweier FK-Zahlen
void swap(double*x, double*y)
{
  double h = *x;
  *x = *y;
  *y = h;
}

// Reihenfolge der Feldelemente im Feld umkehren
void feldUmkehren(double f[], int anzahl)
{
  int i;
  for (i=0;i<anzahl/2;i++)
    swap(&f[i], &f[anzahl-1-i]);
}

// Finde größte und kleinste Zahl im Feld
void miniMax(double f[], int anzahl, double* mini, double* maxi)
{
  int i;
  *mini = *maxi = f[0];
  for (i=1;i<anzahl;i++)
  {
    if (f[i]<*mini)
      *mini = f[i];
    if (f[i]>*maxi)
      *maxi = f[i];
  }
}

void miniMax2(double f[], int anzahl, double* mini2, double* maxi2)
{
  double mini, maxi; int i;

  if (f[0] < f[1])
  {
    mini = *maxi2 = f[0];
    *mini2 = maxi = f[1];
  }
  else
  {
    mini = *maxi2 = f[1];
    *mini2 = maxi = f[0];
  }

  for (i=2;i<anzahl;i++)
  {
    if (f[i]<mini)
    {
      *mini2 = mini; mini = f[i];
    }
    else if (f[i] < *mini2)
        *mini2 = f[i];

    if (f[i]>maxi)
    {
      *maxi2 = maxi; maxi = f[i];
    }
    else
      if (f[i] > *maxi2)
        *maxi2 = f[i];
  }
}

void bubbleSort(double f[], int anzahl)
{
  int i;
  for (i=0;i<anzahl-1;i++)
  {
    int j, tausch=0;
    for (j=0;j<anzahl-1-i;j++)
    {
      if (f[j]>f[j+1])
      {
        swap(&f[j], &f[j+1]);
        tausch++;
      }
    }
    if (tausch==0)
      return;
  }
}

void merge(double f[], int links, int mitte, int rechts)
{
    //Teilfelder, also Feld links von der Mitte und rechts von der Mitte auf ein temporäres neues Feld kopieren

    double l[MAX], r[MAX]; //linkes und rechtes Hilfsfeld

    int i,j, k;
    int nl = mitte - links + 1;
    int nr = rechts - mitte;

    //Schritt 1: kopieren der Original-Daten auf die Hilfsfelder
    for (i = 0; i < nl; i++)
        l[i] = f[links + i];

    for (j = 0; j < nr; j++)
        r[j] = f[mitte + 1 + j];

    //Schritt 2: Sortiert zurück ins Feld kopieren
    i = 0;
    j = 0;
    k = links;
    while( (i < nl) && (j < nr))
    {
        if(l[i] > r[j])
        {
            f[k] = r[j];
            j++;
            k++;
        }
        else
        {
            f[k] = l[i];
            i++;
            k++;
        }
    }
    //Restlichen Elemente vom linke oder rechten Feld in das Hauptfeld zurückspeichern
    while( (i < nl) )
        f[k++] = l[i++];
    while( (j < nr) )
        f[k++] = r[j++];
}

void mergeSort2(double f[], int links, int rechts)
{
    if(links < rechts)
    {
        int mitte = links + (rechts - links)/2;

        mergeSort2(f, links, mitte);
        mergeSort2(f, mitte + 1, rechts);

        //Sortierung
        merge(f, links, mitte, rechts);
    }

}

void feldEinguegen(double f[], int *anzahl, double minvalue)
{
    for (int i = 0; i < *anzahl; ++i)
    {
        if (f[i] >= minvalue)
        {
            // minvalue = 3
            //[1,2,3,4,5] , i=2, anzahl=5
            //[1,2,3,4,5,5] , j= 4
            //[1,2,3,4,4,5] , j= 3
            //[1,2,3,3,4,5] , j= 2, j==i
            for (int j = *anzahl - 1; j>=i; --j)
                f[j+1] = f[j];
            ++(*anzahl);
            ++i;
        }
    }
}

void mergeSort(double f[], int anzahl)
{
    mergeSort2(f, 0, anzahl-1);
}

void findeBereich(double f[], int anzahl, double min, double max, int *pos_start, int *pos_end)
{
    *pos_start = 0;
    *pos_end = 0;

    for (int i = 0; i < anzahl; ++i)
    {
        if ((f[i] >= min) && (f[i] <= max))
        {
            *pos_start = i;
            break;
        }
    }
    *pos_end = *pos_start;
    for (int i = *pos_start; (f[i] <= max) && (i < anzahl); ++i, ++*pos_end)
    {
    }
}
int main(int argc, char** argv)
{
    double f[MAX] = {30,35,40,45,50,55,60,70,80,85,90};
    int anzahl = 11;
    int pos_start, pos_end;

    feldAusgabe("Feld nach dem Erstellen", f, anzahl);
    //feldEinguegen(f, &anzahl, 70);
    //feldAusgabe("Feld nach dem Einfuegen", f, anzahl);

    findeBereich(f, anzahl, 40,  60, &pos_start, &pos_end);
    printf("start: %d\n", pos_start);
    printf("end: %d\n", pos_end);

  /*
  double f[MAX];    // Feld
  int anzahl = 0;   // Anzahl der Zahlen im Feld
  double mini, maxi, mini2, maxi2;

  // ZZG initialisieren
  srand(time(NULL));
  anzahl = feldErstellen(f);    // Feld erstellen
  feldAusgabe("Feld nach dem Erstellen", f, anzahl);
  feldUmkehren(f, anzahl);      // Reihenfolge der Felelemente umkehren
  feldAusgabe("Feld nach dem Umkehren", f, anzahl);
  miniMax(f, anzahl, &mini, &maxi);
  printf("Kleinste Zahl: %8.3lf\n", mini);
  printf("Größte Zahl:   %8.3lf\n\n", maxi);
  miniMax2(f, anzahl, &mini2, &maxi2);
  printf("Zweitkleinste Zahl: %8.3lf\n", mini2);
  printf("Zweitgrößte Zahl:   %8.3lf\n\n", maxi2);

  mergeSort(f, anzahl);
  feldAusgabe("Feld nach Sortieren", f, anzahl);

  bubbleSort(&f[5], anzahl/2);
*/

  return (EXIT_SUCCESS);
}

