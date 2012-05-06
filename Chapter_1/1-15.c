/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
 */

#include<stdio.h>
int convert(int fahr);

main()
{
	int fahr;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		printf("%d\t%d\n", fahr += step, convert(fahr));
	}
}

int convert(int fahr)
{
	return 5 * (fahr - 32) / 9;
}
