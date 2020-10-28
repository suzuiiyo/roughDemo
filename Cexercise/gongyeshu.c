#include<stdio.h>

int main()
{
    int a, b, gcd;
    printf("请输入两个正整数: ");
    scanf("%d %d", &a, &b);

    for(int i = 1; i<=a && i<=b; ++i)
    {
        if((a%i == 0)&&(b%i == 0))
            gcd = i;
    }
    printf("%d ", gcd);
}

/* int sort(int *arr)
{
    int i, j, temp = 0;
    int len = 0;
    len = (int)sizeof(arr) / sizeof(*arr);
    for(i = 0; i<=len; i++)
        for(j = 0; j<=len-1-i; j++)
        {
            if(arr[j] >= arr[j+1])
            {
                arr[j+1] = temp;
                arr[j] = arr[j+1];
                temp = arr[j];
            }
        }
}
*/