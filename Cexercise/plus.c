#include<stdio.h>
int main()
{
    int a, b, c;
    printf("请分别输入a,b的值: ");
    scanf("%d %d", &a, &b);
    c = a + b;
    printf("%d和%d相加的和为：%d", a, b, c);
    
}