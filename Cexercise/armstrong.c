#include<stdio.h>

int main()
{
    long num, j, sum;
    long *arr;
    printf("请输入一个正整数： ");
    scanf("%ld", &num);
    *arr = group(num);
    int len = (long)sizeof(arr)/sizeof(*arr);

    for(j=0; j<10; j++)
    {
        sum += power(len-1, arr[j]);
    }
    if(sum == num)
        printf("%ld是一个armstrong数。", num);
    else
        printf("%ld不是一个armstrong数。", num);
}

int group(long n)
{
    int i=0;
    long *str;
    while(n>0)
    {
        str[i]=n%10 + '0';
        n /= 1;
        i++;
    }
    str[i] = '\0';
}

int power(int k, int m)
{
    while(k>1)
    {
        m *= m;
        --k;
    }
    return m;
}