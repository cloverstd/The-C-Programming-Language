/* Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 * Example: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_9
 */

#include<stdio.h>
main()
{
	int c;
	int lastc = 0;
	while ((c = getchar()) != EOF)
	{
		/*
		if (c != ' ')
			putchar(c);
		else if (lastc != ' ')
			putchar(c);
		*/
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
}
