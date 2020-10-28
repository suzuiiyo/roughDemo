#include<stdio.h>

int main()
{
    int a = 4;
    short b;
    double c;
    int *ptr;

    printf("Line 1 - 变量 a 的大小 = %lu\n", sizeof(a));
    printf("Line 2 - 变量 b 的大小 = %lu\n", sizeof(b));
    printf("Line 1 - 变量 c 的大小 = %lu\n", sizeof(c));

    ptr = &a;
    printf("a的值是 %d\n", a);
    printf("ptr是 %d\n", *ptr);

    a = 10;
    b = (a == 1)? 20 : 30;
    printf("b的值是 %d\n", b);

    b = (a == 10) ? 20 :30;
    printf("b的值是%d\n", b);
}

