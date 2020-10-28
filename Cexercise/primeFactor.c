#include<stdio.h>
#include<math.h>

int main()
{
    int i, n;
    printf("enter the value of the num:\n ");
    scanf("%d", &n);
    printf("%d=", n);

    for(i=2; i<=n; i++)
    {
        while(n%i==0)
        {
            printf("%d", i);
            n /= i;
            if(n!=1)
                printf("*");
        }
    }
    printf("\n");
    return 0;
}