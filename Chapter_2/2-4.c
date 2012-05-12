/* Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that
 * matches any character in the string s2 .
 * */

#include<stdio.h>
void squeeze(char s1[], char s2[]);

int main()
{
	char s2[] = "qwerty";
	char s1[] = "qaqsedrftgyh";
	squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;
}
void squeeze(char s1[], char s2[])
{
  int i, j, k;
  int instr2 = 0;

  for(i = j = 0; s1[i] != '\0'; i++)
  {
    instr2 = 0;
    for(k = 0; s2[k] != '\0' && !instr2; k++)
    {
      if(s2[k] == s1[i])
      {
        instr2 = 1;			// found the same character
      }
    } 

    if(!instr2)
    {
	  //printf("origin: %s\n", s1);
      s1[j++] = s1[i];
	  //printf("j = %d, i = %d\n", j, i);
	  //printf("modified: %s\n\n", s1);
    } 
  }
  s1[j] = '\0';
}
/*
void squeeze(char s1[], char s2[]) {
    int i, j, k;
    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}
*/
