#include<stdio.h>
#include<string.h>

char * s_gets(char *st, int n);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100     //书籍的最大数量

struct book{    //简历 book 模板
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void){
    struct book library[MAXBKS];   // book j结构类型数据
    int count = 0;
    int index;
    printf("请输入书名:    \n");
    printf("按下[enter]结束输入 \n");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) !=NULL && library[count].title[0] != '\0')
    {
        printf("请输入作者：\n");
        s_gets(library[count].author, MAXAUTL);
        printf("请输入价格: \n");
        scanf("%f", &library[count++].value);
        while(getchar() != '\n')
            continue;      //清理输入行
        if(count < MAXBKS)
            printf("请输入下一本书。 \n");
    }
    if(count > 0)      //如果数组内有存书籍
    {
        printf("书的列表:\n");
        for(index = 0; index < count; index++) //遍历已存入的书籍
            printf("%s = %s:$%.2f\n", library[index].title, library[index].author, library[index].value);   //将内容打印出来
    }
    else{
        printf("没有书。  \n");     //否则就打印没书
    }
    return 0;
}

char * s_gets(char * st, int n){      //输入文本(作家)函数
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if(ret_val){
        find = strchr(st, '\n');   //查找换行符
        if(find)      //如果地址不是NULL
            *find = '\0';    //在此处放置一个空字符
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}