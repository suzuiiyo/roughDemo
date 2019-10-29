#include<stdio.h>

int main()
{
    int i;
    int fore=1, back=1;

    for(i=1; i<=20; i++) 
    {
        printf("%12d%12d", fore, back);
        if(i%2==0)
            printf("\n");
        fore += back;
        back += fore;
    }
    return 0;
}