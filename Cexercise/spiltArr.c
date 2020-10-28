#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=0, j=0;
    //int *arr;
    //arr = (int*)malloc(n*sizeof(int));
    int arr[10];
    int even[10], odd[10];
    //printf("please enter the value of n:\n");
    //scanf("%d", &n);
    printf("please enter the element successively:\n");

    while(i<10)
    {
        scanf("%d", &arr[i]);
        i++;
    }

    int e=0 ; int d=0;
    for(i=0; i<10; i++)
    {
        if(arr[i]%2==0)
        {
            even[e] = arr[i];  
            e++;
        }
        else
        {
            odd[d] = arr[i];
            d++;  
        }
    }

    printf("\nthe follow is the original array:\n");
    for(i=0; i<10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nthe follow is the even array:\n");
    for(i=0; i<e; i++)
    {
        printf("%d ", even[i]);
    }
    printf("\nthe follow is the odd array:\n");
    for(i=0; i<d; i++)
    {
        printf("%d ", odd[i]);
    }
}