#include<stdio.h>

int A=10;
int B=20;
char buy;
int sum, number;

int main(){
    printf("以下是本店的商及价格: \n A 商品每个十元：\n B 商品每个二十元; \n\n");
    printf("请输入你所需要购买的商品(A 或 B):");
    scanf("%c", &buy);
    printf("亲输入所需购买的数量: ");
    scanf("%d", &number);
    sum=buy== 'A'?A*number:B*number;
    printf("\n你所需要的%d个%c商品总共%d元。 \n", number, buy, sum);

    return 0;
}