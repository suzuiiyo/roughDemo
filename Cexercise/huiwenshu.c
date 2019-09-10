#include<stdio.h>
#include<stdlib.h>

int main()
{   
/*    int count=0;
    char *arr = (char*)malloc(20*sizeof(char));
    printf("请输入字符串: ");
    scanf("%s", arr);

    while(scanf("%s", arr) != EOF)
        ++count;
            
    for(int i=0; i<=count; i++)
    {
        if(arr[i] != arr[count-i])
            printf("输入的字符串不是回文字\n");
        else
            printf("输入的字符串是回文字\n");
        printf("%c", arr[i]);
    }  */
    long long n, reversedInteger = 0, remainder, originalInterger;

    printf("请输入一个整数: ");
    scanf("%lld", &n);

    originalInterger = n;

    //翻转
    while(n!=0)
    {
        remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }

    //判断
    if(originalInterger == reversedInteger)
        printf("%lld 是回文数。", originalInterger);
    else
        printf("%lld 不是回文数。", originalInterger);
    
    return 0;
}

