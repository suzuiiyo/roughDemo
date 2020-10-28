#include<stdio.h>

int main()
{
    int day, month, year, sumday=0;
    int monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("\nenter the day, month, year with the format of year/month/day(eg:2017/07/07): \n");
    scanf("%d/%d/%d", &year, &month,&day);
    if(year%400==0||(year%4==0&&year%100!=0))
        {
            monthday[3]=29;
        }
    for(int i=0;i<month;i++)
    {
        sumday += monthday[i];
    }
    sumday += day;
    printf("the day is the %dth day of the year:\n", sumday);
    return 0;
}