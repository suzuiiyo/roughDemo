#include<stdio.h>

int main()
{
    float x, y, z;
    float Max, Min, Mid;
    printf("enter the value of x, y, z: \n");
    scanf("%f %f %f", &x, &y, &z);

    Max = (x>y ? x:y)>z ? (x>y ? x:y):z;
    Min = (x<y ? x:y)<z ? (x<y ? x:y):z;
    Mid = x+y+z-(Max+Min);
    printf("%f %f %f", Max, Mid, Min);
    return 0 ;
}