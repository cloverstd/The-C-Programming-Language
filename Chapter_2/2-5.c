/* Write the function any(s1,s2) , which returns the first location in the string s1 where any
 * character from the string s2 occurs, or -1 if s1 contains no characters from s2 . (The standard
 * library function strpbrk does the same job but returns a pointer to the location.)
 */

#include<stdio.h>

int any(char s1[], char s2[]);
int main()
{
	char s1[] = "test";
	char s2[] = "tahdfg";
	char s3[] = "aecv";
	char s4[] = "aqsf";
	char s5[] = "test";
	char s6[] = "zxcv";
	printf("%d\n%d\n%d\n%d\n%d\n", any(s1, s2),any(s1, s3),any(s1, s4),any(s1, s5),any(s1, s6));
	return 0;
}
int any(char s1[], char s2[])
{
	int i, j;
	int place = -1;
	for (i = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
			{
				place = i;
				break;
			}
		if (place != -1)
			break;
	}
	return place;
}
