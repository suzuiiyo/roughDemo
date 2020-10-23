#include <stdio.h>

void debug_arg(unsigned int num, ...){
    unsigned int i = 0;
    unsigned int *addr = &num;
    for(i=0; i<=num; i++){
        printf("I=%d, value=%d\r\n", i, *(addr + i));
    } 
}

int main(void){
    debug_arg(3, 66, 88, 666);
    printf("\n -------------- \n\n");
    debug_arg(8, 6, 18, 66, 88, 666, 888, 9999, 66666);
    return 0;
}