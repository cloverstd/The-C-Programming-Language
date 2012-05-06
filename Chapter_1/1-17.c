/* Write a program to print all input lines that are longer than 80 characters.
*/

#include<stdio.h>
#define MAXLEN 1000

int get_line(char s[], int lim);

main()
{
	int len;
	char line[MAXLEN];
	while ((len = get_line(line, MAXLEN)) > 0)
	{
		if (len > 10)
			printf("%s", line);
	}
}

int get_line(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if ( c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
