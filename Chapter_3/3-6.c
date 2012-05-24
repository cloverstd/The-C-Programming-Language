/* Write a version of itoa that accepts three arguments instead of two. The third argument is a
 * minimum field width; the converted number must be padded with blanks on the left if necessary to
 * make it wide enough.
 */

#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[MAXLEN];
	int n = 1256;
	int b = 4;
	itob(n, s, b);
	printf("%s\n", s);
	exit(0);
}
void itob(int n, char s[], int b)
{
	int i, j, sign;
	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		j = n % 16;
		s[i++] = (j <= 9) ? j + '0' : j + 'A' - 10;
	} while ( (n /= 16) > 0);
	
	if (sign < 0)
		s[i] = '-';
	while (i < b)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
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
