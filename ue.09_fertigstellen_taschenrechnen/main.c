#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getOP (char*txt)
{
    if (*txt == '+')
    {
        return 1;
    }

    else if (*txt == '-')
    {
        return 2;
    }
    else if (*txt =='*')
    {
        return 3;
    }
    else if (*txt == '/')
    {
        return 4;
    }
    return 0;
}

int getLengthOfNumber ( char* txt)
{
    int zahl = 0;
    int krebs = 0;
    int hiv;

    for (int i = 0; krebs == 0;i++)
    {
        if ((txt[i] >= '0' && txt[i] <= '9') || txt[i] == '.' || txt[i] == '-')
        {
            zahl++;
            if (txt[i] == '.')
            {
                hiv++;
            }
            if (hiv > 1)
            {
                printf ("\n Du wappla hast zwei Komma in einer Zahl eingegeben\n");
                return -1;

            }


        }
        else
        {
            krebs++;


        }
    }
    return zahl;

}

void calc (double num1, double num2, int op, double* ergebnis)
{
    if (op == 1)
    {
        *ergebnis = num1 +num2;
    }
    else if ( op == 2)
    {
        *ergebnis = num1 - num2;
    }
    else if (op == 3)
    {
        *ergebnis = num1 * num2;
    }
    else if (op == 4)
    {
        *ergebnis = num1 / num2;
    }
    else if (op == 0)
    {
        printf("\ein Fehler ist aufgetreten\n");
    }

}




int parseText (char*txt, int laenge, double *ergebnis)
{
    double num1 = 0.0;
    double num2 = 0.0;
    int offset = 0;
    int op = 0;
    int bracket_open = 0;

    if ( *txt =='\0')
    {
        return -1;
    }
    else
    {
        op = getOP(txt);
    }
    if (txt[offset]=='(')
    {
        bracket_open = 1;
        offset++;
    }
    else
    {
        return 0;
    }
    if (txt[offset] == '(')
    {
        offset = offset + parseText(txt+offset,laenge-offset,ergebnis);
        return offset;
    }
    else
    {
        return 0;
    }
    if (op == 0)
    {
        if (sscanf(txt+offset, "%lf", &num1)!=1)
        {
            return-1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        num1 = *ergebnis;
    }
    if (op == 0)
    {
        return -1;
        offset ++;
    }
    else
    {
         return 0;
    }
    if (txt[offset]=='(')
    {
        offset = offset+parseText(txt+offset,laenge-offset,&num2);
    }
    else
    {
        if (sscanf(txt+offset, "%lf",&num2)==1)
        {
            offset = offset+getLengthOfNumber(txt+offset);
        }
        else
        {
            return-1;
        }
    }
    if((op<3)&&(txt[offset]=='*'|| txt[offset]=='/')&&(txt[offset] !=')'))
    {
        offset = offset +parseText(txt+offset,laenge-offset,&num2);
        calc(num1,num2,op,ergebnis);
    }
    else
    {
        calc(num1,num2,op,ergebnis);
    }
    if (txt[offset]==')')
    {
        if(bracket_open == 0)
        {
                return offset;
        }
        else
        {
            return 0;
        }
        offset++;
        if (*(txt-1)=='*'||*(txt-1)=='*')
        {
            return offset;
        }
        else
        {
            return 0;
        }

    }
    else
    {
        return 0;
    }
    if (txt[offset]==')')
    {
        return offset;
    }
    else
    {
        return 0;
    }
    return offset+parseText(txt+offset,laenge-offset,ergebnis);
}

int main(int argc, char** argv) {

    double result;

    parseText(argv[1], strlen(argv[1]), &result);

    printf("Result: %lf", result);
    return 0;
}




