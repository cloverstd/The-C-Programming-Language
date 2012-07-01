#include<stdio.h>
#include<ctype.h>

int getword(char *word, int lim)
{
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#')                     // 增加了下划线和 #
    {
        for ( ; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_')            // 如若不是字母和数字或者下划线就返回到输入中并且跳出循环
            {
                ungetch(*w);
                break;
            }
    }
    else if (c == '\'' || c == '"') 
    {
        for ( ; --lim > 0; w++)
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c)
            {
                w++;
                break;
            }
            else if (*w == EOF)
                break;
    }
    else if (c == '/')
        if ((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);
    *w = '\0';
    return c;
}

int comment(void)
{
    int c;
    while ((c = getch()) != EOF)
        if (c == '*')
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
    return c;
}
