#include<stdio.h>

#define MAXLINE 100
#define TABNIC  8           // 默认 tab 增量大小
#define YES     1
#define NO      0

void esettab(int argc, char *argv[], char *tab);
int atoi(char *s);
int tabpos(int pos, char *tab);

/*
 * entab code
void entab(char *tab);
main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];

    esettab(argc, argv, tab);        // 初始化 tab 位置
    entab(tab);                     // 替换为 tab
    return 0;
}

void entab(char *tab)
{
    int c, pos;
    int nb = 0;                     // 标记 blanks
    int nt = 0;                     // 标记 tabs

    for (pos = 1; (c = getchar()) != EOF; pos++)
    {
        if (c == ' ')
        {
            if (tabpos(pos, tab) == NO)
                ++nb;
            else
            {
                nb = 0;
                ++nt;
            }
        }
        else
        {
            for ( ; nt > 0; nt--)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            else 
                for ( ; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while (tabpos(pos, tab) != YES)
                    ++pos;
        }
    }
}
 */

void detab(char *tab);
main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];

    esettab(argc, argv, tab);        // 初始化 tab 位置
    detab(tab);                     // 替换为 tab
    return 0;
}

void detab(char *tab)
{
    int c, pos = 1;

    while ((c = getchar()) != EOF)
        if (c == '\t')
        {
            do 
                putchar(' ');
            while (tabpos(pos++, tab) != YES);
        }
        else if (c == '\n')
        {
            putchar(c);
            pos = 1;
        }
        else
        {
            putchar(c);
            ++pos;
        }
}

void esettab(int argc, char *argv[], char *tab)
{
    int i, inc, pos;

    if (argc <= 1)
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABNIC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+')
    {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);
        for (i = 1; i <= MAXLINE; i++)
            if (i != pos)
                tab[i] = NO;
            else
            {
                tab[i] = YES;
                pos += inc;
            }
    }
    else
    {
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = NO;
        while (--argc > 0)
        {
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }
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

int tabpos(int pos, char *tab)
{
    if (pos > MAXLINE)
        return YES;
    else
        return tab[pos];
}
