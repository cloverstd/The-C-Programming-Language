/* Write a program to remove all trailing blanks and tabs from each line of input, and to delete
 * entirely blank lines.
 * */

#include<stdio.h>
#define MAXLEN 1000
int get_line(char s[], int lim);
int delete(char s[], int len);

main()
{
	int len;
	int line[MAXLEN];
	while((len = get_line(line, MAXLEN)) > 0)
	{
		if (delete(line, len) > 0)
			printf("%s", line);
	}
}

int get_line(char s[], int lim)
{
	int i, c;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int delete(char s[], int len)
{
	int i = len - 1;
	while (i >= 0 && s[i] == ' ' || s[i] == '\t')
		i--;
	s[++i] = '\n';
	s[++i] = '\0';
	return i;
}
