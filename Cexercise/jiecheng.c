#include<stdio.h>

int main()
{
    long a, factorial=1;
    printf("请输入待求阶乘的正整数: ");
    scanf("%d", &a);

    for(int i=1; i<=a; i++)
        factorial *= i;

    printf("%d的阶乘等于%d", a, factorial);
}