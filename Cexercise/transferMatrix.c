#include<stdio.h>
#include<math.h>

int main()
{
    int a[10][10], transpose[10][10], r, c, i, j;
    printf("please enter the row and column of the matrix: ");
    scanf("%d %d", &r, &c);

    //存储矩阵的元素
    printf("\nenter the element of the matrix: \n");
    
    for(i=0; i<r; ++i)
        for(j=0; j<c; j++)
        {
            printf("enter the element a%d%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    
    //显示矩阵 a[][] */
    printf("\n输入矩阵: \n");
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            printf("%d ", a[i][j]);
            if(j == c-1)
                printf("\n\n");
        }
    //转换
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            transpose[j][i] = a[i][j];
        }
    
    //显示转换后的矩阵 a
    printf("\n转换后的矩阵:\n");
    for(i=0; i<c; ++i)
        for(j=0; j<r; ++j)
        {
            printf("%d   ", transpose[i][j]);
            if(j==r-1)
                printf("\n\n");
        }
    
    return 0;
}