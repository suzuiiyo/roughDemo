#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,num;
    float *data;
    data = (float*) calloc(num, sizeof(float));

    printf("please enter the number of elemnets(1 ~ 100): ");
    scanf("%d", &num);

    if(data == NULL)
    {
        printf("Error!!! ");
        exit(0);
    }

    printf("\n");

    for(i=0; i<num; ++i)
    {
        printf("enter the number %d: ", i+1);
        scanf("%f", data + i);
    }

    for(i=1; i<num; ++i)
    {
        if(*data< *(data+i))
            *data = *(data + i);
    }

    printf("the max element is %.2f", *data);

    return 0;
}