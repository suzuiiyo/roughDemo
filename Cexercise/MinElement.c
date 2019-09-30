#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i=0;
    int *arr;
    arr = (int*)malloc(n*sizeof(int));
    printf("请输入元素个数: \n");
    scanf("%d", &n);
    printf("请依次输入数组元素，并用空格隔开:\n");

    while(i<n)
    {
        scanf("%d", &arr[i]);
        i++;
    }

    for(int j=0; j<n; j++)
    {
        if(arr[j] < arr[0])
            arr[0] = arr[j];
    }

    printf("the largest element is %d", arr[0]);
}