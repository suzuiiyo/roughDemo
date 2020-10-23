#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXTITL 41
#define MAXAUTL 31
#define MAVXBKS 100

char * s_gets(char * st, int n);
struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(){
    struct book library[MAVXBKS];       //book类型结构体数组
    int i;
    int index;
    printf("请问你要录入多少本书信息\n");
    do{
        scanf("%d", &index);
    }while(index > MAVXBKS);
    getchar();
    for(i=0; i<index; i++){
        printf("请输入第%d本书的名称:\n", i+1);
        s_gets(library[i].title, MAXTITL);
        printf("请输入其作者的名字:\n");
        s_gets(library[i].author, MAXAUTL);
        printf("请输入书本价格:\n");
        scanf("%f", &library[i].value);
        getchar();
    }
    for(i=0; i<index; i++){
        printf("%d\t%s 是%s写的 定价为%f元\n", i, library[i].title, library[i].author, library[i].value);
    }
    system("pause");
    return 0;
}

char * s_gets(char * st, int n){
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');            //查找换行符
        if(find)                            //查找地址不为空
            *find = '\0';
        else
            while(getchar() != '\n')
        continue;
    }
    return ret_val;
}