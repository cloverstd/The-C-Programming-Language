// gcc -o 4-3 4-3.c -lm
// need to link the math library
#include<stdio.h>
#include<stdlib.h>		// for atof()
#include<ctype.h>
#include<string.h>
#include<math.h>


#define MAXOP	100
#define NUMBER	'0'
#define MAXVAL	100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char s[]);

int main(int argc, char *argv[])
{
	double op2;
	char s[MAXOP];

	while (--argc > 0)
	{
        ungets(" ");
        ungets(*++argv);
        switch(getop(s))
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				if ((op2 = pop()) != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				if ((op2 = pop()) != 0.0)
					push((int)pop() % (int)op2 );
					//push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknow command %s\n", s);
                argc = 1;
				break;
		}
	}
    printf("\t%.8g\n", pop());
	return 0;
}

int getop(char s[])
{
	int c, i = 0;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])
{
    int len = strlen(s);
    while(len > 0)
        ungetch(s[--len]);
}
