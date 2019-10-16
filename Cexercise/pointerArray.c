#include<stdio.h>

int main()
{
    int data[5], i;
    printf("enter the element: ");

    for(i=0; i<5; i++)
        scanf("%d", data+i);
    
    printf("what you entered is: ");
    for(i=0; i<5; ++i)
        printf("%d\n", *(data+i));
    
    return 0;
}