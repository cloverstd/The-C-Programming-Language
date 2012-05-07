/* Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks
 * to achieve the same spacing. Use the same stops as for detab . When either a tab or a single
 * blank would suffice to reach a tab stop, which should be given preference? */

#include<stdio.h>
#define TAB 8
int main()
{
	int c, nb, nt, pos;
	pos = 1;
	nb = 0;
	nt = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (pos % TAB != 0)
				++nb;
			else
			{
				nb = 0;
				++nt;
			}
		}
		else
		{
			for ( ; nt > 0; --nt)
				putchar('\t');
			if (c == '\t')
				nb = 0;
			else
				for ( ; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos += (TAB - (pos - 1) % TAB) - 1;
		}
		pos++;
	}
	return 0;
}
