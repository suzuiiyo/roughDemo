#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i=0;
    int *arr;
    int *copyArr;
    arr = (int*)malloc(n*sizeof(int));
    copyArr = (int*)malloc(n*sizeof(int));
    printf("please enter the value of n:\n");
    scanf("%d", &n);
    printf("please enter the element of the array successively:\n");

    while(i<n)
    {
        scanf("%d ", &arr[i]);
        i++;
    }

    for(i=0; i<n; i++)
    {
        copyArr[i] = arr[i];
        printf("    %2d       %2d\n", arr[i], copyArr[i]);
    }
}