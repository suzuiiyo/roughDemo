#include<stdio.h>
int main(){
    int a;
    printf("请输入a的值: ");
    scanf("%d", &a);
    int b;
    printf("请输入b的值: ");
    scanf("%d", &b);
    int c = a + b;
    printf("%d\n", c);

    return 0;
}