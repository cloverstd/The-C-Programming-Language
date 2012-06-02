#include<stdio.h>
#include"4-13.c"			// for reverse();

#define MAXLEN 100

void itoa(char *s, int n)
{
	static int i;
	s[i++] = n % 10 + '0';
	if (n / 10)
		itoa(s, n / 10);
	else
	{
		s[i] = '\0';
		reverse(s);
	}
}

int main()
{
	char s[MAXLEN];
	int n = 123456;
	itoa(s, n);
	printf("%s", s);
	return 0;
}
