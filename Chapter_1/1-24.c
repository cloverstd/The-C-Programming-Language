/* Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses,
 * brackets and braces. Don't forget about quotes, both single and double, escape sequences, and
 * comments. (This program is hard if you do it in full generality.)
 */
#include<stdio.h>
#define MAXLEN 10

int main()
{
	int c;
	int lastc = 0;
	int flag_parenthesis = 0;
	int flag_bracket = 0;
	int flag_brace = 0;
	int flag_double_quote = 0;
	int flag_single_quote = 0;
	int flag_comment = 0;

	while ((c = getchar()) != EOF)
	{

		// Check the parentheses, brackets and braces
		if (c == '(')
			flag_parenthesis++;
		if (c == ')')
			flag_parenthesis--;
		if (c == '[')
			flag_bracket++;
		if (c == ']')
			flag_bracket--;
		if (c == '{')
			flag_brace++;
		if (c == '}')
			flag_brace--;
		if (c == '"' && lastc != '\\')		// Check quota and escape sequences
			flag_double_quote++;
		if (c == '\'' && lastc != '\\')
			flag_single_quote++;
		if (c == '*' && lastc == '/')
			flag_comment++;
		if (c == '/' && lastc == '*')
			flag_comment--;
		lastc = c;
	}
	if (flag_parenthesis != 0)
		printf("Mismatching parentheies.\n");
	if (flag_bracket != 0)
		printf("Mismatching brackets.\n");
	if (flag_brace != 0)
		printf("Mismatching braces.\n");
	if (flag_double_quote % 2 != 0)
		printf("Mismatching double quotes.\n");
	if (flag_single_quote % 2 != 0)
		printf("Mismatching single quotes.\n");
	if (flag_comment != 0)
		printf("Comment error.\n");
	return 0;
}

