#include<stdio.h>

int swap(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{   
    int a, b;
    printf("请输入两个数： ");
    scanf("%d %d", &a, &b);
    printf("你输入的两个数分别是: %d, %d", a, b);

    swap(a, b);
    printf("交换后输出的两个数分别是： %d，%d", a, b);
}