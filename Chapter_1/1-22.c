/* Write a program to "fold" long input lines into two or more shorter lines after the last
 * non-blank character that occurs before the n -th column of input. Make sure your program does
 * something intelligent with very long lines, and if there are no blanks or tabs before the
 * specified column.
 */
#include<stdio.h>
#define DIVIDE 80

int main()
{
	int c;
	int count = 0;		//记录当前的位置
	while ((c = getchar()) != EOF)
	{
		if (count == DIVIDE)
		{
			if (c != ' ' && c != '\t')	// 判断是否在断行位置为字母，若是字母自己输出c，知道空格或者制表符就换行
			{
				count--;
				putchar(c);
			}
			else
			{
					putchar('\n');
					count = 0;
			}
		}
		else
			putchar(c);
		count++;
	}

	return 0;
}
