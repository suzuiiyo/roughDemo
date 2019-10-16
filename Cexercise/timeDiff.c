#include<stdio.h>

struct TIME
{
    int seconds;
    int minutes;
    int hours;
};

void differenceBetweenTimePeriod(struct TIME t1, struct TIME t2, struct TIME *diff);

int main()
{
    struct TIME startTime, stopTime, diff;

    printf("enter start time: \n");
    printf("enter hours、 minutes、 secods: ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("enter stop time: \n");
    printf("enter hours、 minutes、 seconds: ");
    scanf("%d %d %d", &stopTime.hours, &stopTime.minutes, &stopTime.seconds);

    //calculate difference
    differenceBetweenTimePeriod(startTime, stopTime, &diff);

    printf("\ndifference:%d:%d:%d - ", startTime.hours, startTime.minutes,startTime.seconds);
    printf("\ndifference:%d:%d:%d ", stopTime.hours, stopTime.minutes,stopTime.seconds);
    printf("= %d:%d:%d\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}

void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff)
{
    if(stop.seconds > start.seconds)
    {
        --start.minutes;
        start.seconds += 60;
    }

    diff->seconds = start.seconds - stop.seconds;
    if(stop.minutes > start.minutes)
    {
        --start.hours;
        start.minutes += 60;
    }

    diff->minutes = start.minutes - stop.minutes;
    diff->hours = start.hours - stop.hours;
}