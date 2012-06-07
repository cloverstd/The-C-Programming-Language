#include<string.h>

#define MAXLEN 1000
#define MAXSTOR 5000

int getline(char *, int);

int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
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
