#include<stdio.h>

void strcat(char *s, char *t)
{
	while(*s)
		s++;
	while(*s++ = *t++)
		;
}

int main()
{
	char s[] = "test1";
	char t[] = "A test";
	strcat(s, t);
	printf("%s", s);
	return 0;
}
