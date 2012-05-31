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

int main()
{
	int type;
	double op2, v;
	char s[MAXOP];
	double variable[26];
	int var = 0;
	int i;
	
	for (i = 0; i < 26; i++)
		variable[i] = 0.0;

	while ((type = getop(s)) != EOF)
	{
		switch (type)
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
			case '=':
				pop();
				if (var >= 'A' && var <= 'Z')
					variable[var - 'A'] = pop();
				else
					printf("error: no variable name\n");
				break;
			case '\n':
				v = pop();
				printf("\t%.8g\n", v);
				break;
			default:
				if (type >= 'A' && type <= 'Z')
					push(variable[type - 'A']);
				else if (type == 'v')
					push(v);
				else
					printf("error: unknow command %s\n", s);
				break;
		}
		var = type;
	}
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
