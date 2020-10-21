#include<stdio.h>
#include "max.h"
#include "source.h"

int main(void){
    int num1;
    int num2;
    int result;
    printf("请输入num1的值: ");
    scanf("%d", &num1);
    printf("请输入num2的值: ");
    scanf("%d", &num2);

    result = max(num1, num2);
    printf("result的值为: %d\n", result);

    int sum = add(num1, num2);

    int diff = sub(num1, num2);
    printf("num1和num2的和为: %d\n", sum);
    printf("num1和num2的差为: %d\n", diff);
}