#include<stdio.h>
#include<stdlib.h>		// for atof()
#include<ctype.h>
#include<string.h>

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
	double op2, op1;
	char s[MAXOP];

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
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			case 'p':				// print the top
				op2 = pop();		// pop, sp--
				printf("%g\n", op2);
				push(op2);			// push, sp++
				break;
			case 'd':				// copy the top and push it to the stack
				op2 = pop();		// pop, sp--, and save to op2
				push(op2);
				push(op2);
				break;
			case 's':				// swap
				op2 = pop();
				op1 = pop();
				push(op1);
				push(op2);
				break;
			case 'c':				// clear the stack
				sp = 0;
				break;
			default:
				printf("error: unknow command %s\n", s);
				break;
		}
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
