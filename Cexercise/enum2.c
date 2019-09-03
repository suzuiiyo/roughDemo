#include<stdio.h>
enum DAY{MON=1, TUE, WED, THU=7, FRI, SAT, SUN};

int main()
{
        enum DAY day;
        for(day=MON;day<=SUN;day++)
        {
                printf("day=%d\n",day);
        }
        return 0;
}