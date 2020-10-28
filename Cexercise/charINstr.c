#include<stdio.h>
#include<string.h>

int main()
{
    char ch, str[100];
    int i, num=0;
    printf("enter the string: \n");
    //scanf("%s", str);
    fgets(str, (sizeof str/sizeof(str[0])), stdin);

    printf("enter the character you want to query: \n");
    scanf("%c", &ch);

    for(i=0; str[i]!='\0'; ++i)
    {
        if(ch == str[i])
            ++num;
    }

    printf("the numbers that %c shows in %s is: %d", ch, str, num);
    return 0;
}


