#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN    100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;                              // 最后一个记号的类型
char token[MAXTOKEN];                       // 最后一个记号的字符串
char name[MAXTOKEN];                        // 标识符名
char datatype[MAXTOKEN];                    // 数据类型为 char、int 等
char out[1000];

void errmsg(char *);
int prevtoken = NO;

int main()
{
    while (gettoken() != EOF)
    {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();                              // 分析该行的其余部分
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void)          // 返回下一个标记
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    if (prevtoken == YES)
    {
        prevtoken = NO;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch, too many characters\n");
    else
        buf[bufp++] = c;
}
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; )       // 统计字符 * 的个数
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " point to");
}

void dirdcl(void)
{
    int type;

    if (tokentype == '(')               // 形式为 (dcl)
    {
        dcl();
        if (tokentype != ')')
            //printf("error: missing )\n");
            errmsg("error: missing )\n");
    }
    else if (tokentype == NAME)         // 变量名
        strcpy(name, token);
    else
        //printf("error: expected name or (dcl)\n");
        errmsg("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

void errmsg(char *msg)
{
    printf("%s", msg);
    prevtoken = YES;
}
