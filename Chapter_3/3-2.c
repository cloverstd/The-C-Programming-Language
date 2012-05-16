/* Write a function escape(s,t) that converts characters like newline and tab into visible escape
 * sequences like \n and \t as it copies the string t to s . Use a switch . Write a function for the
 * other direction as well, converting escape sequences into the real characters.
 */

#include<stdio.h>

#define MAXLEN 1000

int escape(char s[], char t[]);

int main()
{
	char s[MAXLEN];
	char t[] = "The\tquick\tbrown\tfox\tjumps\tover\ta\tlazy\tdog!\nThe quick brown fox jumps over a lazy dog!\n";
	printf("%s\n", t);
	escape(s, t);
	printf("%s\n", s);
	return 0;
}
int escape(char s[], char t[])
{
	int i, j;
	int n;
	for (n = 0; t[n] != EOF; n++)
		;
	for (i = 0, j = 0; i < n; i++, j++)
	{
		switch(t[i])
		{
			case '\n': s[j++] = '\\'; s[j] = 'n'; break;
			case '\t': s[j++] = '\\'; s[j] = 't'; break;
			default: s[j] = t[i]; break;
		}
	}
	s[++j] = '\0';
	return j;
}
