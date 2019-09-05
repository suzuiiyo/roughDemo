#include<stdio.h>

int main()
{
    int a, b, c, t1, t2, t3;
    printf("请输入三个不等的整数: ");
    scanf("%d %d %d", &a, &b, &c);
    t1 = a > b ? a : b;
    t2 = a > c ? a : c;
    t3 = t1 > t2 ? t1 : t2;
    printf("三个数中较大的是:%d ", t3);
}