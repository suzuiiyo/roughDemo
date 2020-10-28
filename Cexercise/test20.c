#include <stdio.h>


void swap(int *x, int *y)
{
    int tp;
    tp = *x;
    *x = *y;
    *y = tp;
}

int main( int argc, char *argv[])
{
    int a, b;
    printf("请输入两个需要交换的数\n", a, b);
    scanf("%d %d", &a, &b);
    swap(&a, &b); //实参类型为首地址
    printf("交换结果为 a = %d, b = %d\n",a,b);
    return 0;
}

