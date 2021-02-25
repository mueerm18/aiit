
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[])
{
    double durchschnitt= 0;
    double eingabe[100];
    double falscheeingabe[5000];
    double min = 0;
    double max = 0;
      int a = 0;
      int b = 0;
      int x = 0;
      int y = 0;


    int zaehler = 0;

    for(int a = 0; a < argc; a++)
 {

      y =  sscanf( argv[a], "%lf", eingabe[a]);
      if (y == 1)
    {

      zaehler++;
        if (zaehler > 10)
      {
          return 1;

      }

    }

  }

    for(y = argc - zaehler; y < argc; y++)
    {

      x = sscanf(argv[y], "%lf", &falscheeingabe[y]);
      if(x != 1)
      {

        printf("\n\tKeine Buchstaben\n\n");
        return 1;

      }

    }


    for(y = 0; y < (argc-zaehler); y++){

    if (strcasecmp("-sum", argv[k+1]) == 0)
    {

        durchschnitt = 0;
        for(int b = 0; b < argc; b++)
        {

          durchschnitt = durchschnitt + eingabe[b];

        }

      printf("\nSumme:\t %lf\n", durchschnitt);

    }

      else if (strcasecmp("-avg", argv[y + 1]) == 0)
    {
        durchschnitt = 0;
        for(int l = 0; b < argc; b++
        {

          durchschnitt = durchschnitt + eingabe[b];

        }
      durchschnitt = durchschnitt / zaehler;
      printf("\nDurchschnitt:\t %lf\n", durchschnitt);

    }

      else if (strcasecmp("-min", argv[y + 1]) == 0)
    {

      durchschnitt = 0;
      min = eingabe[argc - zaehler];
        for(int b = argc - zaehler; b < argc; b++)
      {

          if (eingabe[b] < min)
        {

            min = eingabe[b];

        }
      }
      printf("\nMinimal:\t %lf\n", min);
    }

      else if (strcasecmp("-max", argv[y + 1]) == 0)
    {

      durchschnitt = 0;
      max = eingabe[0];
        for(l = 0; b < argc; b++)
    {

          if (eingabe[b] > max)
        {

            max = eingabe[b];
        }
    }

      printf("\nMaximal:\t %lf\n", max);

    }

  }

  return 0;

}
