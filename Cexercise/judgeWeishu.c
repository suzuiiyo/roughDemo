#include<stdio.h>

int main()
{
    long long num;
    int count = 0;

    printf("输入一个整数: ");
    scanf("%lld", &num);

    while(num != 0)
    {
        num /= 10;
        ++count;
    } 

    printf("数字%d是%d位数", num, count);
    
}