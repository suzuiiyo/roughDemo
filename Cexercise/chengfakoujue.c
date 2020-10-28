#include<stdio.h>

int main()
{
    int i=0, j=0;
    int product =0;
    
    for(i=1; i<=9; i++)
    {
        for(j=1; j<=10-i; j++)
        {
            product = i*j;
            printf("%d*%d=%d\t", i, j, product);
        }
        printf("\n");
    }
    return 0;
}