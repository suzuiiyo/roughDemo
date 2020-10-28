#include<stdio.h>

int main()
{
    int i, j, row;
    printf("«Î ‰»Î¡– ˝: ");
    scanf("%d", &row);

    for(i=1; i<=row; i++)
    {
        for(j=i; j<=100; j += row)
            printf(" %3d", j);
        
        printf("\n");
    }
    return 0;
}