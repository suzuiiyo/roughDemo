#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i=0;
    int *arr, sum=0;
    arr = (int *)malloc(n*sizeof(int));
    printf("请输入元素个数: ");
    scanf("%d", &n);

    while(i<n)
    {
        printf("请输入数组元素: ");
        scanf("%d", &arr[i]);
        sum += arr[i];
        i++;
    }
    printf("%d", sum);
}

