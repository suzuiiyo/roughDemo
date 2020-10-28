#include <stdio.h>

int main()
{
    int now =1, prev_1= 1,prev_2=0;
    printf("%i\n", now);
    for(int i = 1;i<40;i++)
    {
        now = prev_1+prev_2;
        printf("%i\n", now);
        prev_2 = prev_1;
        prev_1 = now;
    }
}