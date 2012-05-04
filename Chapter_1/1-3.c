/* Modify the temperature conversion program to print a heading above the table. 
 Example: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_3
*/

#include<stdio.h>
main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		// 温度下限
	upper = 300;	// 温度上限
	step = 20;		// 步长

	fahr = lower;
	printf("fahr\tcelsius\n");
	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%4.0f\t%7.1f\n", fahr, celsius);
		//fahr = fahr + step;
		fahr += step;
	}
}
