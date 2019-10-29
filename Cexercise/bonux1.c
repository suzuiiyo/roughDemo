#include<stdio.h>

int main()
{
    double embllish, bonus=0;
    int flags;
    printf("please enter the number of the emblish(unit: hundred thousands):\n");
    scanf("%lf", &embllish);

    flags = (int)(embllish/10);
    flags = flags > 10? 10:flags;

    switch(flags){
        case 10:
            bonus +=  (embllish-100)*0.01;
            embllish = 100;
        case 9:
        case 8:
        case 7:
        case 6:
            bonus += (embllish-60)*0.015;
            embllish = 60;
        case 5:
        case 4:
            bonus += (embllish-40)*0.03;
            embllish = 40;
        case 3:
        case 2:
            bonus += (embllish-20)*0.05;
            embllish = 20;
        case 1:
            bonus += (embllish-10)*0.075;
            embllish = 10;
        case 0:
            bonus += embllish*0.1;
    }
    printf("%lf\n", bonus);
    return 0;
}