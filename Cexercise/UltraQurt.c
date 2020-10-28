#include<stdio.h>

int main()
{
    int i, j;
    int num;
    for(i=2; i<=84; i++)
    {   
        for(j=2; j<=i; j++)
        {
            if(i*i-j*j==168)
            {
                num = i*i - 268;
                printf("%d + 100 = %d*%d\n", num, j, j);
                printf("%d + 100 + 168 = %d*%d\n", num, i, i);
            }
        }
    }
    return 0;
}