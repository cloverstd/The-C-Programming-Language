#include<ctype.h>
#include<stdio.h>

#define BUFSIZE 100
#define SIZE 10

char buf[BUFSIZE];
int bufp = 0;

int getch()
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

int getint(int *pn)
{
	int c, sign;
	int d;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);		// 压回输入流
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		d = c;
		if (!isdigit(c = getch()))
		{
			if (c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main()
{
	int i;
	int result;
	int arr[SIZE];
	for (i = 0; i < SIZE && (result = getint(&arr[i])); i++)
		printf("arr[%d] = %d, result = %d\n", i, arr[i], result);
	return 0;
}
