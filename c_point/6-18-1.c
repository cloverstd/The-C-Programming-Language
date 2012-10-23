#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
find_char( char const *source, char const *chars );

int
main(void)
{
    char *str_test1 = "ABCDEF";
    char *str_test2 = "BQWTU";
    /*
    char *str_test1 = NULL;
    char *str_test2 = NULL;
    */
    char *p_find, *p_find_test;
    p_find = find_char( str_test1, str_test2 );
    if( p_find == NULL)
        printf( "NULL\n" );
    else
        putchar(*p_find);

    p_find_test = strpbrk( str_test1, str_test2);
    if( p_find_test == NULL)
        printf( "NULL\n" );
    else
        putchar(*p_find_test);

    exit( EXIT_SUCCESS );
}

char *
find_char(char const *source, char const *chars)
{
    char *pi, *pj;

    if ( source == NULL || chars == NULL)
        return NULL;

    for( pi = chars; *pi != '\0'; pi++ )
    {
        for( pj = source; *pj != '\0'; pj++)
            if( *pj == *pi)
                return pi;
    }

    return NULL;
}
