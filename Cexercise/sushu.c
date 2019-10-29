#include <stdio.h>
#include<math.h>

int main()
{
    int i, j;
    for(i=101; i<200; ++i)
    {   
        for(j=2; j<sqrt(i); j++)
        {
            if(i%j == 0)
                break;
        }
        if(j>sqrt(i))
            printf("%d is a prime number \n", i);
        /*else
            printf("%d is not a prime number \n", i); */
    }
    return 0;
}