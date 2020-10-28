#include<stdio.h>

int main()
{
    int num;
    printf("请输入一个正整数: ");
    scanf("%d", &num);

    int i, sum = 0;
    for(i = 0; i <= num; i++)
        sum += i;
    
    printf("小于等于%d的自然数之和为%d", num, sum);
}