#include<stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = daytab[leap];           // 数组名就是地址
    while(--month)
        day+= *++p;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = daytab[leap];
    while(yearday > *++p)
        yearday -= *p;
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}

int main()
{
    int *pmonth, *pday;
    int days;
    int month = 1;
    int day = 1;
    pmonth = &month;
    pday = &day;

    days = day_of_year(2012, 2, 1);
    month_day(2012, 32, pmonth, pday);
    printf("days = %d\n", days);
    printf("*pmonth = %d, *pday = %d", *pmonth, *pday);
    return 0;
}
