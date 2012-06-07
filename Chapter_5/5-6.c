#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

int get_line(char *s, int lim)
{
	int c;
	int i;
	char *p;

	p = s;

	for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; i++)
		*s++ = c;
	if (c == '\n')
		*s++ = '\n';
	*s = '\0';
	return (int)(s - p);
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

void reverse(char *s)
{
	char *p;
	int c;
	int len = 0;
	int count;
	while(*s++)
		len++;
	//s--; 
	//s--;
	count = len + 1;        // 还要算上 '\0'
	while(count--)
		s--;
	for(p = s + len - 1; s < p; s++, p--)
	{
		c = *s;
		*s = *p;
		*p = c;
	}
}

void itoa(int n, char *s)
{
	int sign;
	
	sign = (n > 0 ? 1 : -1);
	n *= sign;

	do {
		*s++ = n % 10 + '0';
	} while(n /= 10); 
	*s = '\0';
}

int main()
{
	char s[MAXLEN];
	int len;

	len = get_line(s, MAXLEN);
	puts(s);
	printf("%d\n", len);
	printf("%d\n", atoi(s));
	itoa(atoi(s), s);
	reverse(s);
	printf("%s", s);
	return 0;
}
