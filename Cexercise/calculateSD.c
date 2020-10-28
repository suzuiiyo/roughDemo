#include<stdio.h>
#include<math.h>

int main()
{
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;

    printf("please enter the value of row: ");
    scanf("%d", &r);
    printf("please enter the value of column：");
    scanf("%d", &c);

    printf("\nplease enter the element of the first dimension: \n");

    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            printf("enter the element a%d%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }

    printf("enter the second dimension: \n");
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            printf("enter the element a%d%d： ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    
    //相加

    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            \

            
            sum[i][j]=a[i][j] + b[i][j];
        }
    //显示结果
    printf("\nthe result of adding the two-dimension array: \n\n");

    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            printf("%d    ", sum[i][j]);

            if(j==c-1)
            {
                printf("\n\n");
            }
        }
    
    return 0;
}