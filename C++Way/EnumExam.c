#include<stdio.h>

int main(void){
    enum MONTH{A=1, B, C, D, F=10};
    enum MONTH month=A;
    for(month=A; month<F; month++)
        printf("the value of month is :%d \n", month);
    
    return 0;
}