#include<stdio.h>

int strend(char *s, char *t)
{
	char *bs = s;
	char *bt = t;

	while (*s)			// 把指针指向字符串末尾
		s++;
	while (*t)
		t++;

	for ( ; *t == *s; s--, t--)
		if (t == bt || s == bs)			// 到达指针开头就跳出循环
			break;

	if (*t == *s && t == bt && *s != '\0')			// 匹配的条件之一是 t 指针到达了开始处
		return 1;
	else
		return 0;
}

int main()
{
	char *s = "A dog is a pet";
	char *t1 = "pet";
	char *t2 = "Adsgpet";
	
	printf("%s\n%s\n", (strend(s, t1) ? "match" : "not match"), (strend(s, t2) ? "match" : "not match"));
	return 0;
}
