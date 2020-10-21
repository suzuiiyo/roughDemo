#include <stdio.h>
void swap(int *x, int *y);
void swap(int *x, int *y){
    int temp;
    //这里操作的是指针指向的值,而不是指针
    temp = *x;
    *x = *y;
    *y = temp;
    //倘若直接交换指针a, b的值不会交换
    //temp = x;
    //x = y;
    //y = temp;
}

int main(int argc, char *argv[]){
    int a = 5;
    int b = 10;
    swap(&a, &b);
    printf("交换结果为 a = %d, b= %d\n", a, b);
    return 0;
}
