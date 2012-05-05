/* Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 */

#include<stdio.h>
#define MAXLEN 10
#define OUT 0
#define IN 1
main()
{
	int c, arr[MAXLEN + 1];
	int wordlens = 0;	// 记录单词长度
	int maxval = 0;		// 储存单词长度中频率最大值
	int thisval = 0;	// 当前单词长度的频率
	int stage = OUT;
	int i;
	for (i = 0; i <= MAXLEN; i++)
		arr[i] = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (stage == IN)
				stage == OUT;
			if (wordlens > MAXLEN)	// 如果单词长度大于最大值
				thisval = ++arr[MAXLEN];
			else 
				thisval = ++arr[wordlens - 1];
			if (thisval > maxval)
				maxval = thisval;
			wordlens = 0;
		}
		else
		{
			if (stage == OUT)
				stage = IN;
			wordlens++;
		}
	}
	/*
	printf("maxval = %d\n", maxval);		//test
	for(i = 0; i <= MAXLEN; i++)			//test
		printf("%d = %d\n", i, arr[i]);
	*/

	// 打印直方图
	int j;
	for (i = maxval; i > 0; i--)
	{
		printf("%4d |", i);
		for (j = 0; j <= MAXLEN; j++)
		{
			if (arr[j] >= i)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}
	printf("     +");
	for (i = 0; i <= MAXLEN; i++)
		printf("---");
	printf("\n      ");
	for (i = 0; i < MAXLEN; i++)
		printf(" %d ", i + 1);
	printf(">10\n");
	printf("Done.\n");
}
