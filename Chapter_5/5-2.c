#include<ctype.h>
#include<stdio.h>
#include<math.h>

#define BUFSIZE 100
#define SIZE 10

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getfloat(double *pn)
{
	int c, sign;
	double float_number = 0.0;
	int is_float = 0;
	int count = 0;

	while (isspace(c = getch()))		// 跳过空格
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);					// 输入不是一个数字，返回输入流中
		return 0;
	}

	sign = (c == '-') ? -1 : 1;		// 储存符号位

	if (c == '+' || c == '-')
		c = getch();			// 读取下一个字符
	for (*pn = 0; isdigit(c) || c == '.'; c = getch())
	{
		if (c == '.' && is_float == 0)
		{
			is_float++;
			count++;
			continue;			// 跳过此次循环，忽略掉 .
		}
		else if (c == '.' && is_float == 1)		// 如果第二次出现. 则跳出循环
		{
			return 0;
		}

		if (is_float == 0)
			*pn = 10.0 * *pn + (c - '0');
		else if (is_float == 1)
		{
			float_number = float_number + (c - '0') * pow(10, -count);
			count++;
		}
	}

	*pn += float_number;
	*pn *= (float)sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main()
{
	double arr[SIZE];
	int i, val;
	for (i = 0; i < SIZE && (val = getfloat(&arr[i])); i++)
		printf("arr[%d] = %lf, val = %d (%s)\n", i, arr[i], val, ( val == EOF ? "number" : "not number"));
	return 0;
}
