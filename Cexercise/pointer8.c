#include<stdio.h>
#include<time.h>

void getSeconds(unsigned long *par);

int main()
{
    unsigned long sec;

    getSeconds( &sec);

    printf("Number of seconds: %d\n", sec);

    return 0;
}

void getSeconds(unsigned long *par)
{
    *par = time(NULL);
    return;
}