/* Write a loop equivalent to the for loop above without using && or ||.
 */

for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	s[i] = c;

// without using && or ||
// Method 1
for (i = 0; i < lim - 1; ++i)
{
	c = getchar();
	if (c == '\n')
		break;
	else if (c == EOF)
		break;
	s[i] = c;
}

// Method 2
int flag = 0;
i = 0;
while (flag != 1)
{
	c = getchar();
	if (c == EOF)
		flag = 1;
	else if (c == '\n')
		flag = 1;
	else if (i == lim -1)
		flag = 1;
	else 
		s[i] = c;
	++i;
}
