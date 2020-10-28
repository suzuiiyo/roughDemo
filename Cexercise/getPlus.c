#include<stdio.h>

int main()
{
    int a, b, c;
    printf("请依次输入两个整数: ");
    scanf("%d %d", &a, &b);
    c = a + b;
    printf("输入的两个整数的和为:%d ", c);
    return 0;
}