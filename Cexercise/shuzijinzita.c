#include<stdio.h>

int main(){
    int i,j,k,n;
    printf("请输入数字金字塔基座宽度(正奇数):");
    scanf("%d",&n);
    for(k=1;k<=(n+1)/2;k++)
    {
        for(i=1;i<(n+1)/2+1-k;i++)    
            printf(" ");
        for(j=k;j<(2*k);j++) 
            printf("%d ",j);
        for(j-=2;j>=k;j--) 
            printf("%d ",j);        
        printf("\n");
    }
}