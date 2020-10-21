#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int score[10];
    int len = sizeof(score)/sizeof(int);
    int count=0;   //定计数器，统计有多少人达到平均分
    int i;
    srand((unsigned)time(NULL));

    //产生数组
    for(i=0; i<len; i++){
        score[i] = rand()%68 + 32;
        printf("score[%d]=%d\t", i, score[i]);
    }

    //对数据进行求和
    int sum =0;
    for(i=0; i<len; i++){
        sum += score[i];
    }

    //求平均分
    double arg=sum/len;
    //判断有多少人达到平均分;
    for(i=0; i<len; i++){
        if(score[i]>arg){
            count++;
        }
    }

    //输出平均分和人数
    printf("\n总分为: %d\n平均分为: %0.2f\n超过平均分的人有: %d个\n", sum, arg, count);
}

