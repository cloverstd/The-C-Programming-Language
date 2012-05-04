/* Write a program that prints its input one word per line.
 */

#include<stdio.h>
#define OUT 0
#define IN 1
main()
{
	int c;
	int stage = OUT;	//目前的状态是在单词外
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (stage == IN)	
			//如果是空格、制表符或者换行符，并且在状态是在单词内就换行，并且把状态转换为单词外，当输入的第一个字符为空格、制表符或者换行符时，舍弃掉
			{
				putchar('\n');
				stage = OUT;
			}
		}
		else if (stage == OUT)	
		//如果不是空格、制表符和换行符，并且在状态是单词外，则把状态转换为单词内，并且打印字符，当第一个字符不为上述时，转换状态并且打印
		{
			stage = IN;
			putchar(c);
		}
		else	//上述都不是说明位于单词内
			putchar(c);
	}
}
