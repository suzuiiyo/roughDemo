#include<stdio.h>

int main()
{
    int dividend , divisor, quotient, remainder;
    printf("请依次输入被除数和除数: ");
    scanf("%d %d: ", &dividend, &divisor);

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    printf("商为： %d, 余数为: %d", quotient, remainder);
    return 0;

}