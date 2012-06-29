#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define NUMERIC 1
#define DECR    2
#define FOLD    4
#define DIRC     8
#define LINES   100
#define MAXSTOR 100
#define MAXLINES    1000

int charcmp(char *, char *);
void error(char *);
int numcmp(char *, char *);
void readargs(int argc, char *argv[]);
int readlines(char *lineptr[], char *linestor, int maxlines);
void my_sort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int order);
int get_line(char s[], int lim);
double my_atof(char *);
int my_atoi(char *);
void substr(char *s, char *t);

char option = 0;
int pos1 = 0;
int pos2 = 0;

int main(int argc, char *argv[])
{
    char *lineptr[LINES];
    int nlines;
    int rc = 0;
    char linestor[MAXSTOR];

    readargs(argc, argv);
    if ((nlines = readlines(lineptr, linestor, LINES)) > 0)
    {
        if (option & NUMERIC)
            my_sort((void **)lineptr, 0, nlines - 1,
                    (int (*)(void *, void *))numcmp);
        else
            my_sort((void **)lineptr, 0, nlines - 1,
                    (int (*)(void *, void *))charcmp);
        writelines(lineptr, nlines, option & DECR);
    }
    else
    {
        printf("input too big to sort\n");
        rc = -1;
    }
    return rc;
}

void readargs(int argc, char *argv[])
{
    int c;

    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+')
    {
        if (c == '-' && !isdigit(*(argv[0] + 1)))
            while (c = *++argv[0])
                switch (c)
                {
                    case 'd':
                        option |= DIRC;
                        break;
                    case 'f':
                        option |= FOLD;
                        break;
                    case 'n':
                        option |= NUMERIC;
                        break;
                    case 'r':
                        option |= DECR;
                        break;
                    default:
                        printf("sort: illegal option %c\n", c);
                        error("Usage: sort -dfnr [+pos1] [-pos2]");
                        break;
                }
        else if (c == '-')
            pos2 = my_atoi(argv[0] + 1);
        else if ((pos1 = my_atoi(argv[0] + 1)) < 0)
            error("Usage: sort -dfnr [+pos1] [-pos2]");
    }
    if (argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");
}

#include<math.h>
#include<string.h>

#define MAXSTR  100


int numcmp(char *s1, char *s2)
{
    double v1, v2;
    char str[MAXSTR];

    substr(s1, str);
    v1 = my_atof(str);
    substr(s2, str);
    v2 = my_atof(str);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int charcmp(char *s, char *t)
{
    char a, b;
    int i, j, endpos;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIRC) ? 1 : 0;

    i = j = pos1;
    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);
    do {
        if (dir)
        {
            while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
                i++;
            while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
                j++;
        }
        if (i < endpos && j < endpos)
        {
            a = fold ? tolower(s[i]) : s[i];
            i++;
            b = fold ? tolower(t[j]) : t[j];
            j++;
            if (a == b && a == '\0')
                return 0;
        }
    } while (a == b && i < endpos && j < endpos);
    return a-b;
}

void substr(char *s, char *str)
{
    int i, j, len;

    len = strlen(s);
    if (pos2 > 0 && len > pos2)
        len = pos2;
    else if (pos2 > 0 && len < pos2)
        error("substr: string too short");
    for (j = 0, i = pos1; i < len; i++, j++)
        str[j] = s[i];
    str[j] = '\0';
}

double my_atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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

void writelines(char *lineptr[], int nlines, int decr)
{
    int i = 0;

    if (decr)
        for (i = nlines - 1; i > 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}

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

void error(char *s)
{
    printf("%s\n", s);
    exit(1);
}

void my_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return ;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    my_sort(v, left, last - 1, comp);
    my_sort(v, last + 1, right, comp);
}

int my_atoi(char *s)
{
	int integer = 0;
	while (*s == ' ')
		s++;
	while (*s >= '0' && *s <= '9')
		integer = integer * 10 + (*s++ - '0');
	return integer;
}
