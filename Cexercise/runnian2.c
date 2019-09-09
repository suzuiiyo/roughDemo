#include<stdio.h>

int main()
{
    int year;
    do
    {
        printf("请输入年份 ");
        scanf("%d", &year);
        getchar();
        
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            printf("%d年是闰年 ", year);
        else
            printf("%d年不是闰年 ", year);
    } while (~scanf("%d", &year));
    return 0;
}