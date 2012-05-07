/*i program detab that replaces tabs in the input with the proper number of blanks to space to the
 * next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a
 * symbolic parameter?
 */

#include<stdio.h>
#define TAB 9
int main()
{
	int c;
	int pos = 0;	// 记录当前为止
	while ((c = getchar()) != EOF)
	{
		pos++;
		if (c == '\n')
			pos = 0;
		if (c == '\t')
			while ((pos % TAB) != 0)
			{
			printf(" ");
			pos++;
			}
		else
			putchar(c);
	}
	return 0;
}
