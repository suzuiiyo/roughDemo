#include<stdio.h>

int main()
{
    long num;
    int factor[100], j=0;
    printf("请输入一个整数: ");
    scanf("%ld", &num);

    for(int i=1; i<=num; i++)
    {
        if(num%i==0)
        {
            factor[j] = i;
            j++;
            printf("%d %d %d\n", i, j, factor[j]);;
        }
    }
}