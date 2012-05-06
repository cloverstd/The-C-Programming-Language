/* rite a function reverse(s) that reverses the character string s . Use it to write a program that
 * reverses its input a line at a time.
 */

#include<stdio.h>
#define MAXLEN 1000
int get_line(char s[], int lim);
void reverse(char s[]);

int main()
{
	int len;
	char line[MAXLEN];
	while ((len = get_line(line, MAXLEN)) > 0)
	{
		reverse(line);
		printf("%s", line);
	}
	return 0;
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

void reverse(char s[])
{
	int i = 0;
	char temp;
	while (s[i] != '\0')
		++i;
	--i;
	if (s[i] == '\n')
		--i;
	int j = 0;
	while (j < i)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		i--;
		j++;
	}
}
