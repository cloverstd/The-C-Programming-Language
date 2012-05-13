/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to
 * the rightmost n bits of y, leaving the other bits unchanged.
 */

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}

/* 
 * xxx...xnnnx...xxx	x
 * yyy...........nnn	y
 *
 * 对x中的n位清零
 * 把y中除最右边的n位以外的其他位都清零并且左移到第p位处
 * 然后对前面两步的结果值进行OR操作
 * xxx...x000x...xxx	x
 * 000...0nnn0...000	y
 * -----------------
 * xxx...xnnnx...xxx	x
 *
 * 为了对x中的n位清零，我们用一个屏蔽码与x进行AND操作
 * 这个屏蔽码从p开始的b位都是0,其他位则全为1
 * 首先是
 * ~0 << n
 * 然后是
 * ~(~0 << n)
 * 接下来是
 * ~(~0 << n) << (p + 1 - n)
 * 再后来是
 * ~(~(~0 << n) << (p + 1 - n))
 * 再接着是
 * x & ~(~(~0 << n) << (p + 1 - n))
 * 对y的操作是
 * ~(~0 << n)
 * 然后是
 * y & ~(~0 << n)
 * 接下来
 * (y & ~(~0 << n)) << (p +1 -n)
 * 最后两者进行OR操作
 */
