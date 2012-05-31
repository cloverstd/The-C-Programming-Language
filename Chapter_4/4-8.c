// gcc -o 4-3 4-3.c -lm
// need to link the math library
#include<stdio.h>

char buf = 0;

int getch(void);
void ungetch(int);

int getch(void)
{
	int c;
	c = (buf != 0 ? buf : getchar());		// 取字符
	buf = 0;
	return c;
}

void ungetch(int c)
{
	if (buf != 0)
		printf("ungetch: too many characters\n");
	else
		buf = c;							// 压入字符
}
