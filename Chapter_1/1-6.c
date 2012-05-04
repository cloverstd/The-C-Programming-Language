/* Verify that the expression getchar() != EOF is 0 or 1.
 * Example: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_6
 */

#include<stdio.h>
main()
{
	int n = (getchar() != EOF);
	printf("n = %d\n", n);
}
