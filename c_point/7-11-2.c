#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n);

int main(void)
{
    printf("%d\n", gcd(16, 12));
    return EXIT_SUCCESS;
}

int gcd(int m, int n)
{
    if (m <= 0 || n <= 0)
        return 0;
    if (m % n == 0)
        return n;

    if (m % n > 0)
        return gcd(n, m % n);
}
