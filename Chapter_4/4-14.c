#include<stdio.h>
#define swap(t, x, y) {t temp; temp = x; x = y; y = temp;}

int main()
{
	int x = 2;
	int y = 3;
	swap(int, x, y);
	printf("x = %d, y = %d", x, y);
	return 0;
}
