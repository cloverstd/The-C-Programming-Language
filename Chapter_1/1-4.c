/* Write a program to print the corresponding Celsius to Fahrenheit table.
 * Example: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_4
 */

#include<stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 100;
	step = 20;

	printf("celsius\tfahr\n");
	for (celsius = lower; celsius <= upper; celsius += step)
	{
		fahr = 32.0 + celsius / (5.0 / 9.0);
		printf("%.0f\t%.2f\n", celsius, fahr);
	}
}
