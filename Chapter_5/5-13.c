#include<stdio.h>
#include<string.h>

#define MAXLINES 1000
#define MAXSTOR 5000
char *lineptr[MAXLINES];

int get_line(char s[], int lim)
{
    int c;
    int i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}



int atoi(char *s)
{
	int integer = 0;
	while (*s == ' ')
		s++;
	while (*s >= '0' && *s <= '9')
		integer = integer * 10 + (*s++ - '0');
	return integer;
}


int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLINES];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while((len = get_line(line, MAXLINES)) > 0)
    {
        if (nlines >= maxlines || p + len > linestop)       // 当地址超过了最大地址时就溢出了，跳出
            return -1;
        else {
            line[len - 1] = '\0';       // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int print_n)
{
    int count = nlines - print_n + 1;
    while (--count > 0)
        lineptr++;
    while (print_n-- > 0)
        printf("%s\n", *lineptr++);
}

int main(int argc, char *argv[])
{
    int nlines;
    char linestor[MAXSTOR];

    int print_n = 10;

    if (argc == 1)
        print_n = 10;
    else if (argc == 2 && (*++argv)[0] == '-')
    {
        print_n = atoi(argv[0] + 1);
        if (print_n > MAXLINES && print_n <= 0)
        {
            print_n = 10;
        }
    }
    else
        printf("Usage: tail [-n]\n");


    if ((nlines = readlines(lineptr, linestor,  MAXLINES)) >= 0)
    {
        if (nlines < print_n)
            print_n = nlines;
        printf("\n\nThe last %d lines:\n", print_n);
        writelines(lineptr, nlines, print_n);
        return 0;
    }
    else
    {
        printf("error: input too big to tail\n");
        return 1;
    }
} 
