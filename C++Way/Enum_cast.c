#include<stdio.h>

enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
}weekend;

int main(){
    weekend=MON;
    printf("day is %d\n", weekend);
    //遍历枚举元素
    while(weekend <= SUN){
        printf("枚举元素: %d \n", weekend);   //类型强制转换
        weekend = (enum DAY)(weekend + 1);
    }
}