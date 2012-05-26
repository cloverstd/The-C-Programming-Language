#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 1000

int strrindex(char s[], char t[]);

int main()
{
	char s[] = "1234567896789";
	char t[] = "789";
	int postion = strrindex(s, t);
	printf("postion = %d", postion);
	exit(0);
}

int strrindex(char s[], char t[])
{
	int i, j, k,  postion = -1;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0 , k = 0; t[k] != '\0' || s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')		// ensure t is in end
			postion = i;
	}
	return postion;

}
