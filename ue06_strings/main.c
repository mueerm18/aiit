
#include <stdio.h>
#include <string.h>

int mystrlen(char *text)
{
    int n;
    for(n=0; text[n] != 0; ++n)       //NULL = 0 = '\0'
        ;
    return n;
}

int main ()
{
  //Ein Text wird immer mit einem NULL-Zeichen abgeschlossen
  //Das Nullzeichen hat den Wert 0
  //
    char satz[] = "Das ist mein erster Text";

    int f[3];

    //satz[0]='A';
    //satz[1]='B';
    satz[2]=0;

    //printf gibt nur jene Zeichen aus die vor der Terminierung stehen!!
    printf("%s", satz);
    //Zeichen nach der Terminierung ausgeben!
    printf("%s", &satz[3]);

    int laenge = strlen(satz);
    printf("\nLaenge = %d Zeichen", laenge);
    printf("\nmystrlen(satz) = %ld Bytes\n", mystrlen(satz));
    printf("\nsizeof(satz) = %ld Bytes\n", sizeof(satz));
    printf("\nsizeof(laenge) = %ld Bytes\n", sizeof(laenge));
    printf("\nsizeof(f)/sizeof(int) = %ld Bytes\n", sizeof(f)/sizeof(int));


    //Strings kopieren
    char ziel[200];
    strcpy(ziel, satz);
    //ziel = satz;      //geht nicht!
    printf("ziel: %s\n", ziel);

    char ziel2[5];
    //strcpy(ziel2, satz); //VERBOTEN -> ziel2 ist zu klein!! -> kann zu einem komischen Verhalten des Programm.
    strncpy(ziel2, satz, 4);
    ziel2[4]=0; // !!! strncpy kopiert in diesem nicht die 0
    printf("ziel2: %s\n", ziel2);
    printf("0 -> 0x%02x %c\n", ziel2[0], ziel2[0]);
    printf("1 -> 0x%02x %c\n", ziel2[1], ziel2[1]);
    printf("2 -> 0x%02x %c\n", ziel2[2], ziel2[2]);
    printf("3 -> 0x%02x %c\n", ziel2[3], ziel2[3]);
    printf("4 -> 0x%02x %c\n", ziel2[4], ziel2[4]);

    //strcmp -> vergleichen von Strings
    char name1[] = "Kolb";
    char name2[] = "Krassmugg";

    int rv = strcmp(name1, name2);
    printf("1 strcmp -> %d\n", rv);

    char name3[] = "KRASSMUGG";
    rv = strcmp(name1, name3);
    printf("2 strcmp -> %d\n", rv);

    rv = strcasecmp(name1, name3);
    printf("3 strcmp -> %d\n", rv);

    /*
    //Umwandlung von Groﬂbuchstaben zu Kleinbuchstaben
    for (i = 0; i<9; ++i )
    {
        if(name3[i] >= 'A' && name3[i] <= 'Z')
           name3[i] = name3[i] + ('A' - 'a')
    }
    */

    //satz[24] = 'A';

    char wort1 [] = "Das";
    char wort2 [] = "Wetter";
    char wort3 [] = "ist";
    char wort4 [] = "bewoelkt";

    char ganzerSatz [20] = "AAAAAAAAAAAAAAAAAAAA";

    strncpy(ganzerSatz, wort1, sizeof(ganzerSatz));
    printf("len=%d    %s\n", strlen(ganzerSatz), ganzerSatz);

    strncat( ganzerSatz, " ", sizeof(ganzerSatz) - strlen(ganzerSatz) - 1 );
    //"Das\s\0"
    printf("len=%d   %s\n", (int)strlen(ganzerSatz), ganzerSatz);

    strncat(ganzerSatz, wort2, sizeof(ganzerSatz) - strlen(ganzerSatz) - 1 );
    printf("len=%d   %s\n", (int)strlen(ganzerSatz), ganzerSatz);

    strncat( ganzerSatz, " ", sizeof(ganzerSatz) - strlen(ganzerSatz) - 1 );
    printf("len=%d   %s\n", (int)strlen(ganzerSatz), ganzerSatz);

    strncat( ganzerSatz, wort3, sizeof(ganzerSatz) - strlen(ganzerSatz) - 1 );
    printf("len=%d   %s\n", (int)strlen(ganzerSatz), ganzerSatz);

    strncat( ganzerSatz, " ", sizeof(ganzerSatz) - strlen(ganzerSatz) - 1 );
    printf("len=%d   %s\n", (int)strlen(ganzerSatz), ganzerSatz);

    strncat( ganzerSatz, wort4, sizeof(ganzerSatz) - strlen(ganzerSatz) - 1 );
    printf("len=%d   %s\n", (int)strlen(ganzerSatz), ganzerSatz);

    strncat( ganzerSatz, ".", sizeof(ganzerSatz) - strlen(ganzerSatz) - 1 );
    printf("len=%d   %s\n", (int)strlen(ganzerSatz), ganzerSatz);

  return 0;
}

