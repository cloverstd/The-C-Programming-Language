/* Write the function htoi(s) , which converts a string of hexadecimal digits (including an optional
 * 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f,
 * and A through F .
 */

#include<stdio.h>
#define YES 1
#define NO 0
int htoi(char s[]);

int main()
{
	char *test[] =
	{
		"0xABC123",
		"0XABC123",
		"0xabc123",
		"0Xabc123",
		"ABC123",
		"abc123",
		"123",
		"12",
		"1",
	};
	int n = sizeof test / sizeof test[0];
	int i;
	for (i = 0; i < n; i++)
		printf("%d\n", htoi(test[i]));

	
	return 0;
}

int htoi(char s[])
{
	int hexdigit, i, inhex, n;

	i = 0;
	if (s[i] == '0')
	{
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	n = 0;
	inhex = YES;
	for (; inhex == YES; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';		// s[i] to digits, '0' = 48
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;	// s[i] to digits, 'a' = 97
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;	// s[i] to digits, 'A' = 65
		else
			inhex = NO;
		if (inhex == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}

