#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i=0;
    int *arr;
    printf("请输入元素个数：");
    scanf("%d", &n);
    arr = (int *)malloc(n*sizeof(int));

    while(i<n)
    {
        printf("请依次输入数组元素: ");
        scanf("%d", &arr[i]);
        i++;
    }

    for(int j=0; j<n; j++)
        printf("arr[%d]=%d, ",j ,arr[j]);
}