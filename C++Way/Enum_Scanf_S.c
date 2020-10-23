#include<stdio.h>
#include<stdlib.h>

int main(){
    enum color{red = 1, green, blue};

    enum color favorite_color;

    //用户输入数字来选择颜色
    printf("please enter the color you like:(1. red, 2. green, 3. blue): \n");

    scanf_s("%u", &favorite_color);

    //输出结果
    switch(favorite_color){
        case red:
            printf("You like red!");
            break;
        case green:
            printf("You like green!");
            break;
        case blue:
            printf("You like blue!");
            break;
        default:
            printf("No color you like!");
    }

    return 0;
}