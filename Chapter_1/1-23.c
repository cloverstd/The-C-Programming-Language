/*Write a program to remove all comments from a C program. Don't forget to handle quoted strings and
 * character constants properly. C comments do not nest.
 */

#include<stdio.h>

int main()
{
	int c;
	int flag1 = 0;				// A sign, when /* comment begin
	int flag2 = 0;				// A sign, when */ comment end
	int lastc = 0;
	int quotation = 0;			// quotation sign, even number is in quotation, odd number is outside quotation
	lastc = getchar();			// get the first character
	while ((c = getchar()) != EOF)
	{
			if (flag1 == 0 && (c == '"' || c == '\''))
			{
				if (lastc != '\\')
					quotation++;
			}
			if (c == '*' && lastc == '/')	// sign into /*
			{
				if (flag1 == 0)
					flag1 = 1;
			}
			else if (c == '/' && lastc == '*')		// sign break * /
			{
				if (flag1 == 1)
					flag1 = 0;
			}
			else if (c == '/' && lastc == '/')		// sign // comment
			{
				if (flag2 == 0)
					flag2 = 1;
			}
			if (flag2 == 1 && c == '\n')			// print not in // comment
			{
				flag2 = 0;
				putchar(c);
			}
			else if  (flag2 != 1)
			{
				if (quotation % 2 != 0)		// print quotation
					putchar(c);
				else
					if (flag1 == 0)			// print not in /* */ comment
					{
						if (c != '/')
							putchar(c);
					}
			}
			lastc = c;
	}
	return 0;
}
