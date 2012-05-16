/* Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n
 * bit positions.
 */

unsigned rightrot(unsigned x, int n)
{
	int wordlength(void);
	int rbit;

	while (n-- > 0)
	{
		rbit = (x & 1) << (wordlength() - 1);
		x = x >> 1;
		x = x | rbit;
	}
	return x;
}

int wordlength(void)		// 计算出运行程序的计算机所使用的字长
{
	int i;
	unsigned v = (unsigned) ~0;

	for (i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}
