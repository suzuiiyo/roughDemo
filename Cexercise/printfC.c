#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    for(int i=0;i<4;i++)
    {
        if(i==0||i==3)
            printf(" ***\n");
        else printf("*\n");
    }
}