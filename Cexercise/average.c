#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, loop;
    float average, sum=0.0;
    float *num;
    num = (float *)malloc(n*sizeof(float));
    printf("please the number of n: ");
    scanf("%d", &n);
    
    for(loop=0; loop<n; loop++)
    {   
        printf("please enter the element of the array: ");
        scanf("%f", &num[loop]);
        sum += num[loop];
    }
    average = sum/loop;
    printf("%.4f %.4f", sum, average);
}