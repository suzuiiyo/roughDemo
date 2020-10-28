#include<stdio.h>
#include<stdlib.h>

int main()
{   
    long base, result=1;
    int exponent;
    printf("请输入底的值：");
    scanf("%ld", &base);
    printf("请输入幂的值：");
    scanf("%d", &exponent);

    while(exponent != 0)
    {
        result *= base;
        --exponent;
    }
    printf("%ld的%d次幂等于:%ld\n", base, exponent, result);
}