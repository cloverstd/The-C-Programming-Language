/* Write a program to count blanks, tabs, and newlines.
 * Example: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_8
 */

#include<stdio.h>
main()
{
	int c;
	int count_spaces = 0;
	int count_tabs = 0;
	int count_newline = 0;
	while((c = getchar()) != EOF)
	{
		if (c == ' ')
			count_spaces++;
		else if (c == '\t')
			count_tabs++;
		else if (c == '\n')
			count_newline++;
	}
	printf("There include %d spaces, %d tabs and %d newline.", count_spaces, count_tabs, count_newline);
}
