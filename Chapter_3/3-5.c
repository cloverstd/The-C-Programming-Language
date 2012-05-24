/* Write the function itob(n,s,b) that converts the integer n into a base b character representation
 * in the string s . In particular, itob(n,s,16) formats n as a hexadecimal integer in s .
 */

#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[MAXLEN];
	int n = 1234;
	int b = 16;
	itob(n, s, b);
	printf("%s\n", s);
	exit(0);
}

void itob(int n, char s[], int b)
{
	int sign, number, i;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		number = n % b;
		if ( number <= 9 )
			s[i++] = number + '0';
		else
			s[i++] = number + 'A' - 10;
		// s[j++] = ( number <= 9 ) ? number + '0' : number + 'A' - 10;
	} while ((n /= b) > 0);
	s[i] = '\0';
	if (sign < 0)
		s[i++] = '-';
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
