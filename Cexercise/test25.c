#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
    enum day
    {
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    } workday;
 
    int a = 1;
    enum day weekend;
    weekend = ( enum day ) a;  //ÀàĞÍ×ª»»
    //weekend = a; //´íÎó
    printf("weekend:%d",weekend);
    return 0;
}