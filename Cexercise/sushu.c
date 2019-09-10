#include<stdio.h>
#include<math.h>

int main()
{
    int a, i, flag;
    printf("请输入一个整数： ");
    scanf("%d", &a);

    for(i=2; i<=sqrt(a); i++)
    {
        if(a%i==0)
        {
            flag = 0;
            break;
        }
        else
            flag = 1;
    }

    if(flag==0)
        printf("%d不是素数\n", a);
    else
        printf("%d是素数\n", a);
}