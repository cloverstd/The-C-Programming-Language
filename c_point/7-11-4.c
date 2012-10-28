#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int max_list(int n, ...);

int main(void)
{
    printf("%d\n", max_list(5, 4, 5, 6, 8, 100, 10, -1));
    return EXIT_SUCCESS;
}

int max_list(int n, ...)
{
    va_list var_arg;
    int integer;
    int ii;
    int max;
    va_start(var_arg, n);

    max = va_arg(var_arg, int); // get the first integer
    integer = max;
    while (1)
    {
        integer = va_arg(var_arg, int);
        if (integer < 0)
            break;
        if (max < integer)
            max = integer;
    }
    va_end(var_arg);
    return max;
}
