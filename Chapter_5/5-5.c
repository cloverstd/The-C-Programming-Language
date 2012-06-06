#include<stdio.h>

char *strncpy(char *s, char *t, int n)
{
	while (n--)
		*s++ = *t++;
	return s;
}

void strncat(char *s, char *t, int n)
{
	while (*s)			// 到达 s 的尾部
		s++;

	while (n--)
		*s++ = *t++;
}

int strncmp(char *s, char *t, int n)
{
	for ( ; n != 0; n--)
	{
		if (*s > *t)
			return 1;
		else if (*t == '\0')
			return 0;
		else if (*s < *t)
			return -1;
		s++;
		t++;
	}
	return 0;
}
int main()
{
	char s[] = "This is a string to test.";
	char t1[] = "This is a string to test strncpy.";
	char t2[] = "This is a string to test strncat.";
	char s2[] = "5";
	char t3[] = "4";
	int n = 10;
	
	strncpy(s, t1, n);
	printf("test 1: %s\n", s);

	strncat(s, t2, n);
	printf("test 2: %s\n", s);

	printf("test 3: %d\n", strncmp(s2, t3, n));

	return 0;
}
