#include <stdio.h>
#include <stdlib.h>

void reverse_string( char *string );

int main( void )
{
    char str[] = "This is a test!";

    printf( "%s\n", str );
    reverse_string( str );
    printf( "%s", str );

    exit( EXIT_SUCCESS );
}

void reverse_string( char *string )
{
    char *pi;
    char *p_end = string;
    char temp;

    /* 得到最后一个字符的地址 */
    while( *p_end != '\0' )
        p_end++;

    /* 把指针从 \0 移到 \0 前一位 */
    p_end--;

    for( pi = string; pi < p_end; pi++, p_end-- )
    {
        temp = *pi;
        *pi = *p_end;
        *p_end = temp;
    }
}
