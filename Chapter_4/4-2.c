#include<ctype.h>
#include<stdio.h>
#define MAXLEN 1000
double atof(char s[]);

void main()
{
	char s1[] = "123.45";
	char s2[] = "123.45e-3";
	char s3[] = "123.45E-3";
	printf("%g\n%g\n%g\n", atof(s1),atof(s2),atof(s3));
}
double atof(char s[])
{
	double val, power;
	int count;
	double number;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)		// skip space
		;
	sign = (s[i] == '-') ? -1 : 1;		// sign negative
	if (s[i] == '+' || s[i] == '-')		// skip sign
		i++;
	for (val = 0.0; isdigit(s[i]); i++)	
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0 ; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	number = sign * val / power;
	if ((s[i] == 'e' || s[i] == 'E') && (s[++i] == '-'))
	{
		i++;
		for (count = 0; isdigit(s[i]); i++)	
		{
			count = 10 * count + (s[i] - '0');
		}
		power = 1.0;
		while(count != 0)
		{
			power *= 10.0;
			count--;
		}
		return number / power;
	}
	else
		return number;
}
