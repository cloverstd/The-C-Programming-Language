#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int ascii_to_integer(char *string);

int main(void)
{
    char s[100];
    scanf("%s", s);
    printf("%d\n", ascii_to_integer(s));
    return EXIT_SUCCESS;
}

int ascii_to_integer(char *string)
{
    int integer = 0;
    char *pstr;
    int flag = 1;

    if (*string == '-')
    {
        string++;       // skip minus
        flag = -1;
    }
    else if (*string == '+')
    {
        string++;       // skip minus
        flag = 1;
    }

    for (pstr = string; *pstr != '\0'; pstr++)
    {
        if (*pstr < '0' || *pstr > '9')
            return 0;
        integer += ((*pstr) - '0');
        integer *= 10;
    }

    return integer / 10 * flag;
}

