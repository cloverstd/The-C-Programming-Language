#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE   0

int
del_substr( char *str, char const *substr );

int
main(void)
{
    char test_str1[] = "ABCZXCZXCZXC";
    char test_str2[] = "ZXC";

    printf( "%s\n", test_str1 );
    del_substr( test_str1, test_str2 );
    printf( "%s", test_str1 );
    exit( EXIT_SUCCESS );
}

int
del_substr( char *str, char const *substr )
{
    char *pi, *pj, *pk;
    int len = 0;
    char *p_place = NULL;       /* 记录匹配到字符的地址 */
    int flag = FALSE;

    if ( str == NULL || substr == NULL )
        return 0;

     /* 找到匹配字符的位置 */

    for( pi = str; *pi != '\0'; pi++)
    {
    /* 当 str 中出现一个字符
     * 与 substr 第一个字符相同时进入循环
     * 记录下 str 中字符的地址，匹配余下的字符
    */
        if( *pi == *substr )   
        {
            p_place = pi;
            flag = TRUE;    /* 假设匹配，用于循环的操作 */
            for( pj = substr, pk = pi; *pj != '\0' && flag == TRUE; pj++ )
            {
                if( *pj != *pk++ )
                    flag = FALSE;
                len++;
            }
        }
        if( flag == TRUE )      /* 找到跳出循环 */
            break;
    }

    /*
     * 未找到就返回 0 
    */
    if( flag == FALSE )
        return 0;

    /* test */
    //printf( "%s\nflag = %s", p_place, flag?"TRUE":"FALSE" );

    /* 删除匹配到的字符 */
    for( pi = p_place + len, pj = p_place; *pi != '\0'; pi++, pj++ )
        *pj = *pi;
    *pj = '\0';

    return 1;
}
