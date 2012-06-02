#include<stdio.h>

#define MAXLEN 100

void reverse(char *s)
{
	static int i;
	static int len;
	static int max;
	char c;
	if (len == 0)
	{
		while(s[len++] != '\0')
			;
		max = len;
		len -= 2;
	}
	if (i < len)
	{
		c = s[i];
		s[i++] = s[len];
		s[len--] = c;
		reverse(s);
	}
	else
	{
		s[max] = '\0';
	}
}
/*
int main()
{
	char s[] = "1234567890";
	reverse(s);
	printf("%s", s);
	return 0;
}
*/
