#include<stdio.h>

long a; int b;
int main()
{
    printf("请输入a的值：", a);
    scanf("%d", &a);
    printf("请输入b的值：", b);
    scanf("%d", &b);
    int num = func1(a, b);-1
    printf("%d&%d的值为：%d", a,b, num);
}

int func1(long m, int n)
{
    return m&n;
}
