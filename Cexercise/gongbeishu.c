#include<stdio.h>

int main()
{
    int a, b;
    printf("请输入两个正整数: ");
    scanf("%d %d", &a, &b);
    int common = a>b?a:b;

    while(1)
    {
        if((common%a == 0)&&(common%b == 0))
        {
            printf("%d和%d的最小公倍数为%d", a, b, common);
            break;
        }
        ++common;
    }
    return 0;
}