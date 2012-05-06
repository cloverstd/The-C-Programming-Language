/* Write a program to print a histogram of the frequencies of different characters in its input.
 */

#include<stdio.h>
#include<ctype.h>
#define MAXLEN 127
main()
{
	int c;
	int thisval, maxval = 0;
	int chararr[MAXLEN + 1];
	int i;
	for (i = 0; i <= MAXLEN; i++)
		chararr[i] = 0;
	while ((c = getchar()) != EOF)
	{
		thisval = ++chararr[c];
		if (thisval > maxval)
			maxval = thisval;
	}
	int j;
	for (i = maxval; i > 0; i--)
	{
		printf("%4d|", i);
		for (j = 0; j <= MAXLEN; j++)
			if (chararr[j] != 0)		// 当字符频率次数为0时，不输出
				if (chararr[j] >= i)
					printf("*");
				else
					printf(" ");
		printf("\n");
	}
	printf("    +");
	for (i = 0; i <= MAXLEN; i++)
		if (chararr[i] != 0)
			printf("-");
	printf("\n     ");
	for (i = 0; i <= MAXLEN; i++)
	{
		if (chararr[i] != 0)
		{
			if (isprint(i))
				printf("%c", i);
			else
				printf(" ");
		}
	}

}
